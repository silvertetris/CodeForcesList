fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val s = br.readLine()
        val firstCnt = s.count { it == '-' }
        val secondCnt = s.count {it=='_'}
        if(firstCnt <2 || secondCnt==0) {
            bw.write("0\n")
        }else {
            val q = firstCnt/2
            bw.write("${q.toLong()*(firstCnt-q).toLong()*secondCnt.toLong()}\n")
        }
    }
    bw.flush()
    bw.close()
}