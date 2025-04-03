fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val temp = br.readLine().split(" ").map { it.toInt() }
        val a = IntArray(27)
        for(i in 1..26) a[i] = temp[i-1]

    }
}