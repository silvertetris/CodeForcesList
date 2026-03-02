fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val (n, m, k) = br.readLine().split(" ").map { it.toInt() }//질문, 질문 리스트, 알고있는 질문
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        val q = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        //질문은 1~n까지 있는데, a에 있는 수들이 거기에서 각 리스트에서 없는 수들이 있음
        if (n == k) {
            repeat(m) {
                bw.write("1")
            }
            bw.write("\n")
        } else if (k + 1 < n) {
            repeat(m) {
                bw.write("0")
            }
            bw.write("\n")
        } else {
            val check = BooleanArray(n+1) {false}
            for(i in 0 until k) {
                check[q[i]] = true
            }
            for(i in 0 until m) {
                if(!check[a[i]]) {
                    bw.write("1")
                } else {
                    bw.write("0")
                }
            }
            bw.write("\n")
        }
    }
    bw.flush()
}