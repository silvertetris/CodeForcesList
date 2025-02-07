fun main() {
    val t = readln().toInt()
    val bw = System.`out`.bufferedWriter()
    repeat(t) {
        val s = readln()
        var cnt = 0
        for(i in s.indices){
            if(s[i]=='1') {
                cnt++
            }
        }
        bw.write("$cnt\n")
    }
    bw.flush()
    bw.close()
}