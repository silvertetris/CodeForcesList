import java.util.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()
    val t = reader.readLine().toInt()

    repeat(t) {
        val n = reader.readLine().toInt()
        val typeList = reader.readLine().split(" ").map { it.toInt() }

        val res = mutableListOf<Pair<Int, Int>>()
        val used = mutableSetOf<Pair<Int, Int>>()
        val pq0 = PriorityQueue(compareBy<Triple<Int, Int, Int>> { it.first }.thenBy { it.second }.thenBy { it.third })
        val pq1 = PriorityQueue(compareBy<Triple<Int, Int, Int>> { it.first }.thenBy { it.second }.thenBy { it.third })

        var sq = 1
        while (sq * sq < n) sq++
        sq *= 3

        for (i in 0 until sq) {
            for (j in 0 until sq) {
                val x = 3 * i + 1
                val y = 3 * j + 1
                val d = 3 * (i + j) + 2
                val base = Triple(d, x, y)
                pq0.add(base)
                pq1.add(base)
                pq1.add(Triple(d + 1, x + 1, y))
                pq1.add(Triple(d + 1, x, y + 1))
                pq1.add(Triple(d + 4, x + 1, y + 1))
            }
        }

        for (tVal in typeList) {
            val pq = if (tVal == 0) pq0 else pq1
            while (true) {
                val (d, x, y) = pq.poll()
                val key = Pair(x, y)
                if (!used.contains(key)) {
                    used.add(key)
                    res.add(key)
                    break
                }
            }
        }

        res.forEach { (x, y) -> writer.write("$x $y\n") }
    }

    writer.flush()
}
