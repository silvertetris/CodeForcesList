import kotlin.math.ceil
import kotlin.math.sqrt

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    fun isPrime(x: Int): Boolean {
        if (x < 2) return false
        for (i in 2..sqrt(x.toDouble()).toInt()) {
            if (x % i == 0) return false
        }
        return true
    }
    repeat(t) {
        val n = br.readLine().toInt()
        val arr = ArrayList<Int>(n)
        arr.add(2)
        arr.add(1)
        var bool = false
        var temp = Pair(0, 0)
        var sum = 3
        for (i in 2 until n) {
            sum += i + 1
            if (!isPrime(ceil(sum.toDouble() / (i + 1).toDouble()).toInt())) {
                if (bool) {
                    arr[temp.first] = i + 1
                    arr.add(temp.second)
                    bool = false
                } else {
                    arr.add(i + 1)
                    temp = Pair(i, i + 1)
                    bool = true
                }
            } else {
                arr.add(i + 1)
            }
        }
        bw.write("${arr.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
}