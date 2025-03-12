import java.math.BigInteger

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val b = br.readLine().split(" ").map { it.toInt() }.toMutableList().sortedDescending()
        var bool = true
        var cnt = BigInteger.ZERO
        bw.write("${b[0]} ")
        for(i in 1 until b.size) {
            if(bool) {
                cnt-=b[i].toBigInteger()
                bool=false
            }else {
                cnt+=b[i].toBigInteger()
                bool=true
            }
        }
        bw.write("${b[0].toBigInteger() - cnt} ")
        for(i in 1 until b.size) {
            bw.write("${b[i]} ")
        }
        bw.write("\n")
    }
    bw.flush()
    bw.close()
}