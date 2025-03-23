fun main() {
    val br = System.`in`.bufferedReader()
    val bw =System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(x, y ) = br.readLine().split(" ").map { it.toBigInteger() }
        var l = (-1).toBigInteger()
        var r = 1_000_000_000_000_000_000.toBigInteger()
        var answer = 0.toBigInteger()
        if(x==y) {
            bw.write("-1\n")
            return@repeat
        }
        while(l<=r) {
            val mid = (l+r)/2.toBigInteger()
            val sum = x+y+mid+mid
            val xor = (x+mid).xor(y+mid)
            if(sum>xor) {
                r = mid-1.toBigInteger()
            }
            else {
                for(i in 0 until mid.toLong()) {

                }
            }
        }
        bw.write("${answer}\n")
    }
    bw.flush()
    bw.close()
}