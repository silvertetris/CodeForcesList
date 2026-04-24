import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val str = StringTokenizer(br.readLine())
        val a = IntArray(n)
        for (i in 0 until n) {
            a[i] = str.nextToken().toInt()
        }
        val tree = LongArray(4 * n)
        val lazy = IntArray(4 * n)

        fun pushDown(node: Int, start: Int, end: Int) {
            if (lazy[node] != 0) {
                val mid = (start + end) / 2

                lazy[node * 2] += lazy[node]
                tree[node * 2] += lazy[node].toLong() * (mid - start + 1)

                lazy[node * 2 + 1] += lazy[node]
                tree[node * 2 + 1] += lazy[node].toLong() * (end - mid)

                lazy[node] = 0
            }
        }

        fun update(node: Int, start: Int, end: Int, l: Int, r: Int, diff: Int) {
            if (l > end || r < start) return
            if (l <= start && end <= r) {
                tree[node] += diff.toLong() * (end - start + 1)
                lazy[node] += diff
                return
            }
            pushDown(node, start, end)
            val mid = (start + end) / 2
            update(node * 2, start, mid, l, r, diff)
            update(node * 2 + 1, mid + 1, end, l, r, diff)
            tree[node] = tree[node * 2] + tree[node * 2 + 1]
        }

        fun query(node: Int, start: Int, end: Int, l: Int, r: Int): Long {
            if (l > end || r < start) return 0L
            if (l <= start && end <= r) return tree[node]

            pushDown(node, start, end)
            val mid = (start + end) / 2
            return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r)
        }
        val stackIdx = IntArray(n)
        val stackWall = BooleanArray(n)
        var sz = 0
        var totalAns = 0L

        for (i in n - 1 downTo 0) {
            if (i < n - 1) {
                if (a[i + 1] > a[i] + 1) {
                    stackWall[sz - 1] = true
                }
            }
            while (sz > 0) {
                val topIdx = stackIdx[sz - 1]
                val topWall = stackWall[sz - 1]

                if (topWall) break

                if (a[topIdx] > a[i]) {
                    update(1, 0, n - 1, topIdx, n - 1, -1)
                    sz--
                } else {
                    break
                }
            }
            stackIdx[sz] = i
            stackWall[sz] = false
            sz++
            update(1, 0, n - 1, i, n - 1, 1)
            totalAns += query(1, 0, n - 1, i, n - 1)
        }

        bw.write("$totalAns\n")
    }
    bw.flush()
}