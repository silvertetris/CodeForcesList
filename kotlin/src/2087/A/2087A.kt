fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(a, b, c) = br.readLine().split(" ").map { it.toInt() }
        for(i in 0 until a) {
            bw.write("$i")
        }
        for(i in 0 until b) {
            bw.write("${(65+i).toChar()}")
        }
        for(i in 0 until c) {
            bw.write("${(97+i).toChar()}")
        }
        bw.write("\n")
    }
    bw.flush()
    bw.close()
}