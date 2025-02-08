import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val t = reader.readLine().toInt()
    for(i in 0 until t) {
        val (x, m) = reader.readLine().split(" ").map { it.toLong()}
        println("$x $m")
    }
    writer.flush()
    writer.close()

}