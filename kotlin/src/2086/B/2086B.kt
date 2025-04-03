import kotlin.math.ceil

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val (n, k, x) = br.readLine().split(" ").map { it.toBigInteger() }
        val a = br.readLine().split(" ").map { it.toInt() }

        val prefixSum = Array(n.toInt() + 1) { 0.toBigInteger() }
        for (i in 1..n.toInt()) {
            prefixSum[i] = prefixSum[i - 1] + a[i - 1].toBigInteger()
        }
        var count = 0L

        for (pos in 1..n.toInt()) {
            val sum = prefixSum[n.toInt()] - prefixSum[pos - 1]

            if (sum >= x) {
                count += k.toInt()
            } else {
                val need = x - sum
                val c = ceil(need.toDouble() / prefixSum[n.toInt()].toLong()).toLong().toBigInteger()

                if (c <= k - 1.toBigInteger()) {
                    count += (k - c).toLong()
                }
            }
        }

        bw.write("$count\n")
    }
    bw.flush()
    bw.close()
}
