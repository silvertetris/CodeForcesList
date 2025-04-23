import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val l = br.readLine().split(" ").map { it.toLong() }
        val r = br.readLine().split(" ").map { it.toLong() }

        var posibSum = 0L
        val best = mutableListOf<Long>()

        for (i in 0 until n) {
            val li = l[i]
            val ri = r[i]

            posibSum += max(li, ri) //가능한 수니까 무조건 큰걸로
            best.add(min(li, ri)) //최선의 경우
        }

        best.sortDescending()

        var bestSum = 0L
        val numGainsToTake = k-1
        for (j in 0 until numGainsToTake) {
            bestSum += best[j]
        }
        val answer = posibSum + bestSum + 1

        bw.write("$answer\n")
    }
    bw.flush()
    bw.close()
}