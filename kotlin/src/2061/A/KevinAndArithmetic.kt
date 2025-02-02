import java.io.BufferedWriter
import java.io.OutputStreamWriter

fun main() {
    val t = readln().toInt()
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    for (i in 0 until t) {
        val n = readln().toInt()
        val list: MutableList<Int> = readln().split(" ").map { it.toInt() }.toMutableList()
        var sum = 0L
        var result = 0L
        for(j in 0 until n) {
            for (k in list.indices) { //첫 계산 만약 없을경우..??
                if(list[k]%2==0 && sum%2==0L) {
                    sum+=list[k]
                    list.removeAt(k)
                    result++
                    while(sum%2!=1L) {
                        sum/=2
                    }
                    break
                }
                if(list[k]%2==1 && sum%2==1L) {
                    sum+=list[k]
                    list.removeAt(k)
                    while(sum%2!=1L) {
                        sum/=2
                    }
                    result++
                    break
                }
            }
            if(sum==0L) {
                sum+=list[0]
                list.removeAt(0)
                continue
            }
        }
        writer.write("$result\n")
    }
    writer.flush()
    writer.close()
}