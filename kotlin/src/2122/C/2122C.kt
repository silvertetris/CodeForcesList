fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val x = IntArray(n)
        val y = IntArray(n)
        repeat(n) { i ->
            val (xi, yi) = br.readLine().split(' ').map{it.toInt()}
            x[i] = xi
            y[i] = yi
        }
        val order = MutableList(n) { it }
        order.sortBy { x[it] }
        println(order.joinToString(" "))
        val half = n / 2
        order.subList(0, half).sortBy { y[it] }
        order.subList(half, n).sortBy { y[it] }
        for (i in 0 until half) {
            bw.write("${order[i] + 1} ${order[n - 1 - i] + 1}\n")
        }
    }
    bw.flush()
    bw.close()
}
