fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t= br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val x = IntArray(n)
        val y = IntArray(n)
        for(i in 0 until n) {
            var temp = br.readLine().split(" ").map { it.toInt()}
            x[i] = temp[0]
            y[i] = temp[1]
        }
    }
}