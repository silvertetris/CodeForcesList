fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val xDp = mutableMapOf<Long, Int>()
        val yDp = mutableMapOf<Long, Int>()

        repeat(n) {
            val (x, y) = br.readLine().split(" ").map { it.toLong() }
            val u = x + y
            val v = x

            xDp[u] = xDp.getOrDefault(u, 0) + 1
            yDp[v] = yDp.getOrDefault(v, 0) + 1
        }

        var u0: Long = -1
        var v0: Long = -1

        for ((u, count) in xDp) {
            if (count % 2 != 0) {
                u0 = u
                break
            }
        }

        for ((v, count) in yDp) {
            if (count % 2 != 0) {
                v0 = v
                break
            }
        }

        val s = v0
        val t = u0 - v0

        bw.write("$s $t\n")
    }

    bw.flush()
    bw.close()
}