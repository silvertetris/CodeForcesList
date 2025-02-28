fun main() {
    val n = readln().toInt()
    val bw = System.out.bufferedWriter()
    val dp = Array(1020) {IntArray(8) {63} }
    dp[0][0] = 0
    for(i in 0 until n) {
        val temp = readln().split(" ")
        var c = temp[0].toInt()
        var s = temp[1]
        var mask = 0
        for( j in s.indices) {
            mask = mask or (1 shl(s[j]-'A'))
        }
        for( m in 0 until 8 ) {
            dp[i+1][m or mask] = minOf(dp[i+1][m or mask], dp[i][m] +c)
            dp[i+1][m] = minOf(dp[i+1][m], dp[i][m])
        }
        if(dp[n][7]>1e6) dp[n][7] = -1
    }
    bw.write("${dp[n][7]}\n")
    bw.flush()
    bw.close()
}