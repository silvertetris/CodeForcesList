fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val p = IntArray(n + 1)
        val tempP = br.readLine().split(" ")
        for (i in 1..n) p[i] = tempP[i - 1].toInt() //그냥 1based 로 옮김 편의상

        val d = IntArray(n + 1)
        val tempD = br.readLine().split(" ")
        for (i in 1..n) d[i] = tempD[i - 1].toInt()

        val cycle = IntArray(n + 1)
        val cycleLength = mutableListOf<Int>()
        val visited = BooleanArray(n + 1)
        var prevCycleIdx = 0

        fun dfs(idx: Int): Int {
            var count = 0
            var v = idx
            while (!visited[v]) {
                visited[v] = true
                cycle[v] = prevCycleIdx
                count++
                v = p[v]
            }
            return count
        }

        for (i in 1..n) {
            if (!visited[i]) {
                prevCycleIdx++
                cycleLength.add(dfs(i))
            }
        }

        val check = BooleanArray(prevCycleIdx + 1) { true }
        var temp = n
        var ans = IntArray(n + 1)

        for (q in 1..n) {
            val idx = d[q]
            val cycleIdx = cycle[idx]
            if (cycleIdx != 0 && check[cycleIdx]) {
                check[cycleIdx] = false
                temp -= cycleLength[cycleIdx - 1]
            }
            ans[q] = n - temp
        }
        ans = ans.drop(1).toIntArray()
        bw.write("${ans.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
}
