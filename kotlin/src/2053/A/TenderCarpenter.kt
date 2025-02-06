import kotlin.math.max
import kotlin.math.min

fun main() {
    val t = readln().toInt()
    val result = StringBuilder()
    repeat(t) {
        val n  = readln().toInt()
        val arr = readln().split(" ").map { it.toInt() }
        var temp =0
        for(j in 1 until n) {
            val mini = min(arr[j-1], arr[j])
            val maxi = max(arr[j-1], arr[j])
            if(mini*2>maxi) {
                result.append("YES\n")
                temp = 1
                break
            }
        }
        if(temp==0) {
            result.append("NO\n")
        }
    }
    print(result)
}