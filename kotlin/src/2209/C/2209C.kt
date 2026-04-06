fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        var ans = 0

        for (i in 1 until n) {
            bw.write("? ${2*i+1} ${2*i+2}\n")
            bw.flush()
            val res = br.readLine().toInt()
            if (res == 1) {
                ans = 2*i+1
            }
        }
        if (ans != 0) {
            bw.write("! $ans\n")
            bw.flush()
        } else {
            bw.write("? 1 3\n")
            bw.flush()
            val res2 = br.readLine().toInt()
            if (res2 == 1) {
                bw.write("! 1\n")
                bw.flush()
            } else {
                bw.write("? 1 4\n")
                bw.flush()
                val temp = br.readLine().toInt()
                if(temp==1) {
                    bw.write("! 1\n")
                    bw.flush()
                } else {
                    bw.write("! 2\n")
                    bw.flush()
                }
            }

        }
    }
    br.close()
    bw.close()
}