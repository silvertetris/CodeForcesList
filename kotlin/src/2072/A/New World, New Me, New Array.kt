import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        var (n, k, p) = br.readLine().split(" ").map { it.toInt() }
        k = abs(k)
        if(n*p<k) {
            bw.write("-1\n")
            return@repeat
        }
        else {
            val q = k/p
            if(k%p !=0 ) {
                bw.write("${q+1}\n")
            } else {
                bw.write("$q\n")
            }
        }
    }
    bw.flush()
    bw.close()
}