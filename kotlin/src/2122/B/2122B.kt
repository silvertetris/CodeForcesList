fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        var result = 0L
        repeat(n) {
            val(a, b, c, d) = br.readLine().split(" ").map { it.toInt() }
            var minOp = 0
            if(b>d) {
                minOp = a+b-d
            }
            if(a>c) {
                minOp = maxOf(a-c, minOp)
            }
            result += minOp
        }
        bw.write("$result\n")
    }
    bw.flush()
    bw.close()
}