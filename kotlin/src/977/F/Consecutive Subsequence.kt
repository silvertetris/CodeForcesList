fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val arr = br.readLine().split(" ").map { it.toInt() }
    var answer = 0
    var current = 0
    val vec = ArrayList<Int>()
    val dp: MutableMap<Int, Int> = sortedMapOf()
    for (i in 0 until n) {
        dp[arr[i]] = maxOf(dp[arr[i]]?:0, (dp[arr[i] - 1]?:0) + 1)
        if (dp[arr[i]]!! > answer) {
            answer = dp[arr[i]]!!
            current = arr[i]
        }
    }
    for (i in n - 1 downTo 0) {
        if (arr[i] == current) {
            current--
            vec.add(i)
        }
    }
    bw.write("${vec.size}\n")
    vec.sort()
    for (i in 0 until vec.size) {
        bw.write("${vec[i] + 1} ")
    }
    bw.flush()
    bw.close()
}