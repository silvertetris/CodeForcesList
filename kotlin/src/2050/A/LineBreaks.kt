fun main() {
    val t = readln().toInt()
    val result = StringBuilder()
    repeat(t) {
        var (n, m) = readln().split(" ").map { it.toInt() }
        var cnt = 0
        for (i in 0 until n) {
            val temp = readln()
            m -= temp.length
            cnt++
            if (m < 0) {
                cnt--
                for (j in i + 1 until n) {
                    readln()
                }
                break
            }
        }
        result.append("$cnt\n")
    }
    print(result)
}