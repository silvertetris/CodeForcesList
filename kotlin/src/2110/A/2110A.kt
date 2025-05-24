fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt() }.toMutableList()
        a.sort()
        var firstCnt = 0
        var secondCnt = 0
        for(i in 0 until n) {
            if((a[i]+a[n-1])%2 != 0) {
                firstCnt++
            }
            else break
        }
        for(i in n-1 downTo 0) {
            if((a[i]+a[0])%2 != 0) {
                secondCnt++
            }
            else break
        }
        bw.write("${minOf(firstCnt, secondCnt)}\n")
    }
    bw.flush()
    bw.close()
}