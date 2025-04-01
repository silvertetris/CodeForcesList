fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        val arr = Array(n) { IntArray(m) { 0 } }
        for (i in 0 until n) {
            arr[i] = br.readLine().split(" ").map { it.toInt() }.sorted().toIntArray()
        }
        val ans = mutableSetOf<Int>()
        var temp = 0
        for(i in 0 until n) {
            for(j in 0 until n) {
                if(arr[j].contains(i)) {
                    ans.add(j+1)
                    break
                }
            }
        }
        if(ans.size!=n) {
            bw.write("-1\n")
            return@repeat
        }
        temp = 0
        arr.sortBy { it[0] }
        for(i in 0 until m) {
            for(j in 0 until n) {
                if(arr[j][i]==temp) {
                    temp++
                } else {
                    bw.write("-1\n")
                    return@repeat
                }
            }
        }
        bw.write("${ans.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
}