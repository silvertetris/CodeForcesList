import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val s = br.readLine()//color
        val a = br.readLine().split(" ").map { it.toInt() } // penalty
        var l = -1
        var r = Int.MAX_VALUE
        while(l+1 <r) {
            val mid = (l+r) /2
            var nk = k
            var lst = 0
            for(i in 0 until n) {
                if(a[i]>mid && s[i]=='R') {
                    lst = 0
                }
                else if(a[i]>mid && s[i]=='B') {
                    if(lst==0) {
                        nk-=1
                        lst=1
                    } else {
                        lst = 1
                    }
                }
            }
            if(nk>=0) {
                r=mid
            }else {
                l=mid
            }
        }
        bw.write("$r\n")
    }
    bw.flush()
    bw.close()
}