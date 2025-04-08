fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val (n, k, x) = br.readLine().split(" ").map { it.toLong() }
        val a = br.readLine().split(" ").map { it.toLong() }
        val total = a.sum()

        if (total * k < x) {
            bw.write("0\n")
            return@repeat
        }

        var l = 1L
        var r = n * k

        while (l <= r) {
            val m = (l + r) / 2
            val cntA = (n * k - m + 1) / n
            val suffix = (n * k - m + 1) % n
            var sum = cntA * total

            for (i in (n - suffix).toInt() until n.toInt()) { //끝에꺼 더 더해주는 작업
                sum += a[i]
            }

            if (sum < x) {
                r = m - 1
            } else {
                l = m + 1
            }
        }

        bw.write("$r\n")
    }

    bw.flush()
    bw.close()
}
