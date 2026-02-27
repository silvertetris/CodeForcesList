fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    fun lexi(a:MutableList<Int>, b:MutableList<Int>): Boolean {//b가 크면 1 아니면 -1
        val minSize = minOf(a.size, b.size)
        for(i in 0 until minSize) {
            if(a[i]!=b[i]) {
                return a[i]<b[i]
            }
        }
        return a.size<b.size
    }

    repeat(t) {
        val n = br.readLine().toInt()
        val inAns = BooleanArray(100_000_1) {false}
        val blogs = Array(n) { IntArray(0) }

        fun change(list: MutableList<Int>, ans: MutableList<Int>) {
            val tmp = ArrayList<Int>()
            for (v in list) {
                if (!inAns[v]) tmp.add(v)
            }
            list.clear()
            list.addAll(tmp)
        }
        for (i in 0 until n) {
            val input = br.readLine().split(" ").map { it.toInt() }
            val arr = IntArray(input[0])
            for (i in 1 until input[0] + 1) {
                arr[i - 1] = input[i]
            }
            blogs[i] = arr
        }

        val set = mutableSetOf<Int>()
        val rev = Array(n) { mutableListOf<Int>() }

        for (i in 0 until n) {
            for (k in blogs[i].size - 1 downTo 0) {
                set.add(blogs[i][k])
            }
            rev[i] = set.toMutableList()
            set.clear()
        }
        val ans = mutableListOf<Int>()
        val visited = BooleanArray(n) { false }
        for(i in 0 until n) {
            var best = -1
            for(j in 0 until n) {
                if(visited[j]) continue
                if(best==-1 || lexi(rev[j], rev[best])) {
                    best = j
                }
            }
            visited[best] = true
            ans.addAll(rev[best])
            for(i in rev[best].indices) {
                inAns[rev[best][i]] = true
            }
            for(j in 0 until n) {
                if(!visited[j]) change(rev[j], ans)
            }
        }
        bw.write("${ans.joinToString(" ")}\n")
    }
    bw.flush()
}