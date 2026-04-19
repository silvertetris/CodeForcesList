import java.util.StringTokenizer

fun main() {
    val br= System.`in`.bufferedReader()
    val bw= System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*\
    감소하지 않는 배열

     */
    repeat(t) {
        val n = br.readLine().toInt()
        val str = StringTokenizer(br.readLine())
        val a = IntArray(n)
        for(i in 0 until n) {
            a[i] = str.nextToken().toInt()
        }

    }
}