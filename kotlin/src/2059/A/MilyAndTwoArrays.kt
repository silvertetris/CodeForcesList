import java.io.BufferedWriter
import java.io.OutputStreamWriter


fun main() {
    val t = readln().toInt()
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    for (i in 0 until t) {
        val n = readln().toInt()
        val a = readln().split(" ").map { it.toInt() }.toMutableSet()
        val b = readln().split(" ").map { it.toInt() }.toMutableSet()
        if((a.size>=2 &&b.size>=2)||a.size>=3 || b.size>=3) {
            writer.write("YES\n")
        }
        else writer.write("NO\n")
    }
    writer.flush()
    writer.close()
}
