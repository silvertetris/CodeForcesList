fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine()
        val s = br.readLine()
        val hyphen = s.count{it=='-'}
        val underBar = s.count { it=='_' }
        if(hyphen <=1 || underBar ==0) {
            bw.write("0\n")
            return@repeat
        }
        else {
            bw.write("${(hyphen/2).toLong() * (hyphen-(hyphen/2)) * underBar}\n")
        }
    }
    bw.flush()
    bw.close()
}