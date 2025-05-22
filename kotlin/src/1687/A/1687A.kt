fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val t= br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() } //버섯 포지션, 시간
        val a = br.readLine().split(" ").map{it.toInt()}
        val preSum = LongArray(n+1) {0}
        preSum[0] = 0
        for(i in 1 .. n) {
            preSum[i] = preSum[i-1] + a[i-1]
        }
        if(n>k) {
            var max = -1L
            for(i in 0 .. n-k) {
                max = maxOf(max, preSum[i+k]-preSum[i])
            }
            bw.write("${max+k.toLong()*(k-1)/2}\n")
        }else {
            bw.write("${preSum[n]+((n.toLong()*k) - (n.toLong()*(n+1)/2))}\n")
        }
    }
    bw.flush()
    bw.close()
}