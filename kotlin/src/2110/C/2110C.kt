fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val d = br.readLine().split(" ").map { it.toInt() }

        val l = IntArray(n)
        val r = IntArray(n)
        for (i in 0 until n) {
            val (a, b) = br.readLine().split(" ").map { it.toInt() }
            l[i] = a
            r[i] = b
        }

        var tempLow = 0
        var tempHigh = 0

        val leastH = IntArray(n + 1) { -1 }
        val maxH = IntArray(n + 1) { -1 }
        leastH[0] = 0
        maxH[0] = 0

        var bool = true

        for (i in 0 until n) {
            val curD = d[i]

            var nextLow: Int
            var nextHigh: Int

            when (curD) {
                0 -> {
                    nextLow = tempLow
                    nextHigh = tempHigh
                }
                1 -> {
                    nextLow = tempLow + 1
                    nextHigh = tempHigh + 1
                }
                else -> {
                    // -1이면 0 or 1 가능하니까 low는 그대로, high는 1 더한값
                    nextLow = tempLow
                    nextHigh = tempHigh + 1
                }
            }

            val nextLeastH = maxOf(nextLow, l[i])
            val nextMaxH = minOf(nextHigh, r[i])

            if (nextLeastH > nextMaxH) {
                bool = false
                break
            }
            //싹다 대입
            leastH[i + 1] = nextLeastH
            maxH[i + 1] = nextMaxH

            tempLow = nextLeastH
            tempHigh = nextMaxH
        }

        //#4. final answer
        if (!bool) {
            bw.write("-1\n")
            return@repeat
        }

        val answer = IntArray(n)
        var curH = leastH[n]

        for (i in n - 1 downTo 0) {
            val prevLeastH = leastH[i]
            val prevMaxH = maxH[i]

            if (curH in prevLeastH..prevMaxH) {
                answer[i] = 0
            } else if (curH - 1 in prevLeastH..prevMaxH) {
                answer[i] = 1
                curH--
            } else {
                bw.write("-1\n")
                return@repeat
            }
        }

        // 원래 d_i 랑 맞는지 아닌지 확인
        for (i in 0 until n) {
            if (d[i] != -1 && d[i] != answer[i]) {
                bw.write("-1\n")
                return@repeat
            }
        }

        bw.write("${answer.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
    br.close()
}
