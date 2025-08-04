fun main() {
    val br =System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
    val dp = IntArray(10_0001) {0}
    var ans = -1
    for(i in 0 until n) {
        var j = 2
        var res = 1
        while(true) {
            if(j*j >a[i]) break
            if(a[i]%j ==0) {
                res = maxOf(res, dp[j]+1, dp[a[i]/j]+1)
            }
            j++
        }
        res = maxOf(res, dp[a[i]]+1)
        j = 2
        while (true) {
            if(j*j >a[i]) break
            if(a[i]%j ==0) {
                dp[j] = maxOf(dp[j], res)
                dp[a[i]/j] = maxOf(dp[a[i]/j], res)
            }
            j++
        }
        dp[a[i]] = maxOf(dp[a[i]], res)
        ans = maxOf(ans, res)
    }
    print(ans)
}