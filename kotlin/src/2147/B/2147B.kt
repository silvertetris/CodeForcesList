fun main() {
    val br= System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val arr = IntArray(2 * n) {0}

        for (i in 0 until n) {
            arr[i] = n - i
        }
        arr[n] = n
        for (i in 1 until n) {
            arr[n + i] = i
        }

        bw.write("${arr.joinToString(" ")}\n")
    }
    bw.flush()
}
