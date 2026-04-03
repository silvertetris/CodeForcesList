fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        for(i in n downTo 1) {
            bw.write("$i ")
        }
        bw.write("\n")
    }
    bw.flush()
}