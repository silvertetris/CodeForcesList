fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val arr= br.readLine().split(" ").map { it.toInt() }
    var answer = 0L
    var current = 0
    var vec = ArrayList<Int>()
    val dp = LongArray(200001){0}
    for(i in 0 until n ) {
        dp[arr[i]] = maxOf(dp[arr[i]], dp[arr[i]-1]+1)
        if(dp[arr[i]]>answer) {
            answer = dp[arr[i]]
            current = arr[i]
        }
    }
    for(i in n-1 downTo 0) {
        if(arr[i] == current) {
            current--
            vec.add(i)
        }
    }
    bw.write("$current\n")
    vec.sort()
    for(i in 0 until vec.size) {
        bw.write("${vec[i]+1} ")
    }
    bw.flush()
    bw.close()
}