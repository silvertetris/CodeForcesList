fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()

    repeat(t) {
        val (n, x) = br.readLine().split(" ").map { it.toInt() }
        val skills = br.readLine().split(" ").map { it.toBigInteger() }.sortedDescending()

        var count = 0
        var teamSize = 0.toBigInteger()

        for (skill in skills) {
            teamSize++
            if (teamSize * skill >= x.toBigInteger()) {
                count++
                teamSize = 0.toBigInteger()
            }
        }

        bw.write("$count\n")
    }

    bw.flush()
    bw.close()
}
