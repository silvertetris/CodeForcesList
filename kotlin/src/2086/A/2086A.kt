fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()//잼 갯수
        bw.write("${n.toLong() * 2}\n")

    }
    bw.flush()
    bw.close()
}