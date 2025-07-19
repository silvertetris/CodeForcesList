fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        if(n<=2&&m<=2) {
            bw.write("NO\n")
        }
        else if(n==1 || m==1) {
            bw.write("NO\n")
        }
        else {
            bw.write("YES\n")
        }
    }
    bw.flush()
    bw.close()
}