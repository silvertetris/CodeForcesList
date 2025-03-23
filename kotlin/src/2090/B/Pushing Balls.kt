fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        val arr = Array(n) { CharArray(m) { '0' } }
        for (i in 0 until n) {
            arr[i] = br.readLine().toCharArray()
        }
        for (i in n - 1 downTo 0) {
            for (j in m - 1 downTo 0) {
                if (arr[i][j] == '1') {
                    var bool = true
                    for (k in i downTo 0) {
                        if (arr[k][j] != '1') {
                            bool = false
                            break
                        }
                    }
                    if (bool) {
                        continue
                    }
                    for (k in j downTo 0) {
                        if (arr[i][k] != '1') {
                            bw.write("NO\n")
                            return@repeat
                        }
                    }
                }
            }
        }
        bw.write("YES\n")
        return@repeat
    }
    bw.flush()
    bw.close()
}