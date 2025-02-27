import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val s = br.readLine()
        val a = br.readLine().split(" ").map { it.toInt() }

        var maxA = 0
        a.forEach { maxA = max(maxA, it) }

        var low = 0
        var high = maxA
        var answer = maxA

        fun isPossible(x: Int): Boolean {
            var totalSegments = 0
            var i = 0
            val len = s.length
            while (i < len) {
                while (i < len && s[i] == 'R' && a[i] > x) {
                    i++
                }
                if (i >= len) break
                val start = i
                while (i < len) {
                    if (s[i] == 'R' && a[i] > x) break
                    i++
                }
                val end = i - 1
                var hasMandatory = false
                for (j in start..end) {
                    if (s[j] == 'B' && a[j] > x) {
                        hasMandatory = true
                        break
                    }
                }
                if (hasMandatory) {
                    totalSegments++
                    if (totalSegments > k) return false
                }
            }
            return totalSegments <= k
        }

        while (low <= high) {
            val mid = (low + high) / 2
            if (isPossible(mid)) {
                answer = mid
                high = mid - 1
            } else {
                low = mid + 1
            }
        }

        bw.write("$answer\n")
    }

    bw.flush()
    bw.close()
    br.close()
}