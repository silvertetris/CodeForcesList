import java.util.StringTokenizer
import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val str = StringTokenizer(br.readLine())
        var p = str.nextToken().toInt()
        var q = str.nextToken().toInt()
        var (n, m) = 0 to 0
        var flag = true
        for (i in 1..100_000) {//n수
            if ((p + 2 * q - i) % (2 * i + 1) != 0) {
                flag = false
                continue
            } else {
                m = (p + 2 * q - i) / (2 * i + 1)
                n = i
                if (p >= abs(m - n)) {
                    flag = true
                    break
                }
            }
        }
        if (flag) {
            bw.write("$n $m\n")
        } else {
            bw.write("-1\n")
        }

    }
    bw.flush()
}