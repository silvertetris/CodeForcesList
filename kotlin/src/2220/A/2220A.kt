import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    3 3 2 1

     */
    repeat(t) {
        val n = br.readLine().toInt()
        val str = StringTokenizer(br.readLine())
        val a = IntArray(n)
        for(i in 0 until n) {
            a[i] = str.nextToken().toInt()
        }
        if(n==1) {
            bw.write("${a[0]}\n")
            return@repeat
        }
        a.sortDescending()
        var flag = true

        for(i in 1 until n) {
            if(a[i-1] == a[i]) {
                flag = false
                break
            }
        }
        if(flag) {
            bw.write("${a.joinToString(" ")}\n")
        } else{
            bw.write("-1\n")
        }
    }
    bw.flush()
}