fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val s = br.readLine()
        val smallCnt = s.count { it == '<' }
        var start = 1+smallCnt
        var small = start
        var big = start
        val list = mutableListOf<Int>()
        list.add(start)
        for(i in 0 until n-1) {
            if(s[i]=='<') {
                list.add(--small)
            }
            else {
                list.add(++big)
            }
        }
        bw.write("${list.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
}