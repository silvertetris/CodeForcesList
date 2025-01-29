import java.io.BufferedWriter
import java.io.OutputStreamWriter

fun main() {
    val t = readln().toInt()
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    repeat(t) {
        val(n, k) = readln().split(" ").map { it.toInt() }
        val arr:Array<Int> = readln().split(" ").map { it.toInt() }.toTypedArray()
        arr.sort()
        var temp =arr.lastIndex
        var result =0
        for(i in 0 ..arr.size/2) {
            if(arr[i]+arr[temp]==k) {
                result++
                temp--
            }

        }
    }
}