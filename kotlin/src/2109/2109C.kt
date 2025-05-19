fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val target = br.readLine().toInt()
        for(i in 0 until 2) {
            bw.write("digit\n")
            bw.flush()
            br.readLine()
        }//7
        bw.write("add -3\n")//4
        bw.flush()
        var bool = true
        val res = br.readLine()

        if(res == "1") {
            bw.write("add -3\n")//1
            bw.flush()
            val res2=br.readLine()
            if(res2=="1") {
                bw.write("add -2\n")
                bw.flush()
                val res3 = br.readLine()
                if(res3=="0") {
                    bool = false//2임
                }
            }
            else {
                bw.write("add -1\n")
                bw.flush()
                br.readLine()
            }
        }else {
            bw.write("add -2\n")
            bw.flush()
            val res = br.readLine()
            if(res=="0") {
                bool = false
            }
        }

        if(bool) {
            bw.write("add ${target-1}\n")
        }
        else {
            bw.write("add ${target-2}\n")
        }
        bw.flush()
        br.readLine()

        bw.write("!\n")
        bw.flush()
        br.readLine()
    }
}