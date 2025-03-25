import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val (n, m, k) = br.readLine().split(" ").map { it.toLong() }
        var l = 1L
        var r = m
        var answer = r

        while (l <= r) {
            val mid = (l + r) / 2

            val temp = m / (mid + 1)
            val remain = m % (mid + 1)
            val max = temp * mid + min(remain, mid)

            if (n * max >= k) {
                answer = mid
                r = mid - 1
            } else {
                l = mid + 1
            }
        }
        bw.write("$answer\n")
    }
    bw.flush()
    bw.close()
}
