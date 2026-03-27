fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        var ans = 0
        for (i in 0 until n step 2) {
            bw.write("? $i ${i + 1}\n")
            bw.flush()
            val res = br.readLine().toInt()
            if (res == 1) {
                ans = i
            }
        }
        for (i in 4 until n-1 step 4) {
            bw.write("? $i ${i - 2}\n")
            bw.flush()
            val res = br.readLine().toInt()
            if (res == 1) {
                ans = i
            }
            bw.write("? ${i - 1} ${i - 3}\n")
            bw.flush()
            val res2 = br.readLine().toInt()
            if (res2 == 1) {
                ans = i - 1
            }
        }
        bw.write("! $ans\n")
        bw.flush()
    }
    br.close()
    bw.close()
}