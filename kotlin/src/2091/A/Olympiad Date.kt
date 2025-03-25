fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val arr = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        var zero = 0 //3
        var one = 0//1
        var three = 0//1
        var two = 0//2
        var five = 0//1
        for (i in 0 until n) {
            if (arr[i] == 0) zero++
            if (arr[i] == 1) one++
            if (arr[i] == 2) two++
            if (arr[i] == 5) five++
            if (arr[i] == 3) three++
            if (zero >= 3 && one >= 1 && three >= 1 && two >= 2 && five >= 1) {
                bw.write("${i+1}\n")
                return@repeat
            }
        }
        bw.write("0\n")
    }
    bw.flush()
    bw.close()
}