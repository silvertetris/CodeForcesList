fun main() {
    val br = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        if (n % 2 == 0) {
            writer.write("-1\n")
            return@repeat
        }
        for (i in 1..n / 2 + 1) {
            writer.write("${2 * i - 1} ")
        }
        for (i in 1..n / 2) {
            writer.write("${2 * i} ")
        }
        writer.write("\n")
    }
    writer.flush()
    writer.close()
}