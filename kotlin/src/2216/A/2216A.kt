import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val str = StringTokenizer(br.readLine())
        val str2 = StringTokenizer(br.readLine())
        var max = -1
        for (i in 0 until k) {
            max = maxOf(max, str.nextToken().toInt())
        }
        max=k
        var cnt = 0
        val list = mutableListOf<Pair<Int, Int>>()
        for (i in 0 until n) {
            val temp = str2.nextToken().toInt()
            list.add(i to max - temp + 1)
            cnt += max - temp + 1
        }
        list.sortBy { it.second }
        bw.write("$cnt\n")
        for (i in 0 until n) {
            for (j in 0 until list[i].second) {
                bw.write("${list[i].first+1} ")
            }
        }
        bw.write("\n")
    }
    bw.flush()
}