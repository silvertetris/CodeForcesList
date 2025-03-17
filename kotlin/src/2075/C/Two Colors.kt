fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    fun binarySearch(a: List<Int>, target: Int): Int {
        var low = 0
        var high = a.size
        while (low < high) {
            val mid = (low + high) / 2
            if (a[mid] >= target) {
                high = mid
            } else {
                low = mid + 1
            }
        }
        return low
    }
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }.sorted()
        var totalWays: Long = 0

        val sumArray = LongArray(m + 1)
        for (i in 0 until m) {
            sumArray[i + 1] = sumArray[i] + a[i]
        }

        for (i in 0 until m) {
            val temp = minOf(n - 1, a[i])

            val l1 = binarySearch(a, n - 1)
            val cnt1 = (m - l1) - if (i in l1..<m) 1 else 0
            totalWays += cnt1 * temp

            val lowerBound = n - temp - 1
            val upperBound = n - 1
            val l2 = binarySearch(a, lowerBound)
            val r2 = binarySearch(a, upperBound)

            var cnt2 = r2 - l2
            var sum = sumArray[r2] - sumArray[l2]

            if (i in l2..<r2) {
                cnt2 -= 1
                sum -= a[i]
            }

            totalWays += cnt2 * (temp - n + 1).toLong() + sum
        }

        bw.write("$totalWays\n")
    }
    bw.flush()
    bw.close()
}
