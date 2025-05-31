fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (a, b, c, d) = br.readLine().split(" ").map { it.toInt() }
        val gelMin = minOf(a, c)
        val floMin = minOf(b, d)
        if (gelMin >= floMin) {
            bw.write("Gellyfish\n")
        } else {
            bw.write("Flower\n")
        }
    }
    bw.flush()
    bw.close()
}