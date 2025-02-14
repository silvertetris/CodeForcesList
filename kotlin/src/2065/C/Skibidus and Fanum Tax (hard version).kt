import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    fun findLower(b: MutableList<Int>, x: Int): Int {
        var l = -1
        var r = b.size

        while (l + 1 < r) {
            val m = l + ((r - l) / 2)

            if (b[m] < x) {
                l = m
            } else {
                r = m
            }
        }

        return if (r == b.size) Int.MAX_VALUE else b[r]
    }
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        var a = br.readLine().split(" ").map { it.toInt() }.toMutableList()
        var b = br.readLine().split(" ").map { it.toInt() }.toMutableList()
        b.sort()
        a[0] = min(a[0], b[0] - a[0])
        for (i in 1 until n) {
            if (max(a[i], b[b.lastIndex] - a[i]) < a[i-1]) {
                bw.write("NO\n")
                return@repeat
            }
            val pos = findLower(b, a[i]+a[i-1])
            var temp = Int.MAX_VALUE
            if(a[i-1]<=a[i]) {
                temp = a[i]
            }
            if(pos!=Int.MAX_VALUE){
                if(a[i-1]<=pos-a[i]) {
                    temp = min(temp, pos-a[i])
                }
            }
            if(temp==Int.MAX_VALUE) {
                bw.write("NO\n")
                return@repeat
            }
            a[i]=temp
        }
        bw.write("Yes\n")
    }
    bw.flush()
    bw.close()
}
