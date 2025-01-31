import kotlin.math.max

fun main() {
    val t = readln().toInt()
    val result = StringBuilder()
    repeat(t) {
        var arr = readln().split(" ").map{it.toInt() }
        val a = arr[0]+arr[1]
        val b = arr[3]-arr[2]
        val aArr = arrayOf(arr[0], arr[1], a, arr[2], arr[3])
        val bArr = arrayOf(arr[0], arr[1], b, arr[2], arr[3])
        var aCnt=0
        var bCnt=0
        for(i in 2 .. 4) {
            if(aArr[i]==aArr[i-1]+aArr[i-2]) {
                aCnt++
            }
        }
        for(i in 2..4) {
            if(bArr[i]==bArr[i-1]+bArr[i-2]) {
                bCnt++
            }
        }
        result.append("${max(aCnt, bCnt)}\n")
    }
    print(result)
}