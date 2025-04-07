fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        var(n, k, x) = br.readLine().split(" ").map { it.toBigInteger() }
        val a = br.readLine().split(" ").map { it.toBigInteger() }.toMutableList()
        if(a.sumOf { it }*k<x) {
            bw.write("0\n")
            return@repeat
        }

        var l = 1
        var r = (n*k).toInt()
        while(l<=r) {
            var m = (r+l)/2
            var cnt_a = (n.toInt()*k.toInt()-m+1)/(n.toInt())
            var suff = (n.toInt()*k.toInt()-m+1)%n.toInt()
            var sum = cnt_a.toBigInteger() * a.sumOf { it }
            for(i in n.toInt()-suff until n.toInt()) {
                sum+=a[i]
            }
            if(sum<x) {
                r = m-1
            }
            else {
                l = m+1
            }
        }
        bw.write("$r\n")
    }
    bw.flush()
    bw.close()
}