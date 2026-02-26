fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val blogs = Array(n) { IntArray(0) }
        for (i in 0 until n) {
            val input = br.readLine().split(" ").map { it.toInt() }
            val arr = IntArray(input[0])
            for (i in 1 until input[0] + 1) {
                arr[i - 1] = input[i]
            }
            blogs[i] = arr
        }

        val set = mutableSetOf<Int>()
        val rev = Array(n) { IntArray(0) }

        for (i in 0 until n) {
            for (k in blogs[i].size - 1 downTo 0) {
                set.add(blogs[i][k])
            }
            rev[i] = set.toIntArray()
            set.clear()
        }

        val used = BooleanArray(n)
        val seen = HashSet<Int>()
        val answer = ArrayList<Int>()

        repeat(n) {
            var best = -1

            for (i in 0 until n) {
                if (used[i]) continue
                if (best == -1) {
                    best = i; continue
                }

                val curblog = rev[i]
                val bestblog = rev[best]

                var idxCur = 0
                var idxBest = 0

                while (true) {
                    while (idxCur < curblog.size && curblog[idxCur] in seen) idxCur++
                    while (idxBest < bestblog.size && bestblog[idxBest] in seen) idxBest++

                    if (idxCur == curblog.size || idxBest == bestblog.size) {
                        if (idxCur == curblog.size && idxBest != bestblog.size) best = i
                        break
                    }

                    if (curblog[idxCur] != bestblog[idxBest]) {
                        if (curblog[idxCur] < bestblog[idxBest]) best = i
                        break
                    }

                    idxCur++
                    idxBest++
                }
            }

            used[best] = true
            for (v in rev[best])
                if (seen.add(v)) answer.add(v)
        }

        for (i in answer.indices) {
            bw.write("${answer[i]} ")
        }
        bw.write("\n")
    }
    bw.flush()
}