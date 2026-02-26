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
        val filteredArr = Array(n) { IntArray(0) }

        for (i in 0 until n) {
            for (k in blogs[i].size - 1 downTo 0) {
                set.add(blogs[i][k])
            }
            filteredArr[i] = set.toIntArray()
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

                var p = 0
                var q = 0

                while (true) {
                    while (p < filteredArr[i].size && filteredArr[i][p] in seen) p++
                    while (q < filteredArr[best].size && filteredArr[best][q] in seen) q++

                    if (p == filteredArr[i].size || q == filteredArr[best].size) {
                        if (p == filteredArr[i].size && q != filteredArr[best].size) best = i//더 작은놈이니까
                        break
                    }

                    if (filteredArr[i][p] != filteredArr[best][q]) {
                        if (filteredArr[i][p] < filteredArr[best][q]) best = i
                        break
                    }

                    p++; q++
                }
            }

            used[best] = true
            for (v in filteredArr[best])
                if (seen.add(v)) answer.add(v)
        }

        for (i in answer.indices) {
            bw.write("${answer[i]} ")
        }
        bw.write("\n")
    }
    bw.flush()
}