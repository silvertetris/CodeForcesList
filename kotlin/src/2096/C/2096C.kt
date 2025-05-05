private const val INF = 1e18.toLong()

fun solveHor(n: Int, h: Array<IntArray>, a: IntArray): Long {
    val dp = Array(n) { LongArray(2) { INF } }
    dp[0][0] = 0L
    dp[0][1] = a[0].toLong()

    for (i in 1 until n) {
        for (x in 0..1) {
            for (y in 0..1) {
                var ok = true
                for (j in 0 until n) {
                    if (h[i - 1][j] + y == h[i][j] + x) ok = false
                }
                if (ok) {
                    if (x == 0) {
                        dp[i][x] = dp[i][x].coerceAtMost(dp[i - 1][y])
                    }
                    if (x == 1) {
                        dp[i][x] = dp[i][x].coerceAtMost(dp[i - 1][y] + a[i])
                    }
                }
            }
        }
    }
    return minOf(dp[n - 1][0], dp[n - 1][1])
}

fun transpose(n: Int, h: Array<IntArray>) {
    for (i in 0 until n) {
        for (j in i + 1 until n) {
            val tmp = h[i][j]
            h[i][j] = h[j][i]
            h[j][i] = tmp
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val h = Array(n) { br.readLine().split(" ").map { it.toInt() }.toIntArray() }
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        val b = br.readLine().split(" ").map { it.toInt() }.toIntArray()

        val horCost = solveHor(n, h, a)
        transpose(n, h)
        val verCost = solveHor(n, h, b)
        val totalCost = horCost + verCost

        if (totalCost >= INF) {
            bw.write("-1\n")
        } else {
            bw.write("$totalCost\n")
        }
    }
    bw.flush()
    bw.close()
}