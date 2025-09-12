import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(n, m) = br.readLine().split(" ").map{it.toInt()}
        val a = br.readLine().split(" ").map{it.toInt()}.toMutableList()
        val b = br.readLine().split(" ").map{it.toInt()}.toMutableList()
        var temp = n
        var cnt = 1
        for(i in 0 until n) {
            if(b.contains(a[i])) {
                b.removeAt(b.indexOf(a[i]))
                temp--
            }
        }
        //temp 하고 b.size
        var ls = 0
        if(temp<=b.size) {
            ls = temp*2
        } else {
            ls = b.size*2 +1
        }
        cnt+=ls
        bw.write("$cnt\n")
    }
    bw.flush()
}