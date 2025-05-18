fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        bw.write("mul 9\n")
        bw.flush()
        br.readLine()

        bw.write("digit\n")
        bw.flush()
        br.readLine()

        bw.write("digit\n")
        bw.flush()
        br.readLine()

        bw.write("add ${n-9}\n")
        bw.flush()
        br.readLine()

        bw.write("!\n")
        bw.flush()
        br.readLine()
    }
}