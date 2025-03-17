import java.math.BigInteger

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val(n, k) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }.toMutableList()
        if(k==1) {
            var max = 0
            for(i in 1 until n-1) {
                max = maxOf(max, a[i])
            }
            if(max<a[0] && max<a[n-1]) {
                bw.write("${a[0]+a[n-1]}\n")
            } else {
                bw.write("${maxOf(max+a[0], max+a[n-1])}\n")
            }
            return@repeat
        }
        a.sortDescending()
        var answer = BigInteger.ZERO
        for(i in 0 .. k) {
            answer+=a[i].toBigInteger()
        }
        bw.write("$answer\n")
    }
    bw.flush()
    bw.close()
}