fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val p = br.readLine().split(" ").map{it.toInt()}.toIntArray()
        var max = 0
        var temp = 0
        val check = BooleanArray(n) {false}
        for(i in 0 until n) {
            val cur = p[i]-1
            if(check[i]) {
                temp--
            }
            check[cur] = true
            temp++
            max = maxOf(temp, max)
        }
        bw.write("$max\n")
    }
    bw.flush()
}