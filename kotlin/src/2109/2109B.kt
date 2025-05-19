fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    fun bit(x: Int): Int {
        if (x <= 1) return 0
        val f = 31 - Integer.numberOfLeadingZeros(x)
        return if ((1 shl f) == x) f else f + 1
    }
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m, a, b) = br.readLine().split(' ').map { it.toInt() }
        val r = minOf(a, n - a + 1)
        val c = minOf(b, m - b + 1)
        val reduceR = bit(r) + bit(m)
        val reduceC = bit(n) + bit(c)
        val ans = 1 + minOf(reduceR, reduceC)
        bw.write("$ans\n")
    }
    bw.flush()
    bw.close()
}