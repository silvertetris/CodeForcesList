fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val s = br.readLine()
        var cnt = 0
        var bool = false
        for (i in 0 until s.length - 1) { //마지막 전까지 체크
            if (s[i] == '(') cnt++ else cnt--
            if (cnt == 0) {
                bool = true
                break
            }
        }
        bw.write("${if (bool) "YES" else "NO"}\n")
    }
    bw.flush()
    bw.close()
}