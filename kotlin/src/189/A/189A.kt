fun main() {
    val(n, a, b, c) = readln().split(" ").map { it.toInt() }
    val dp = IntArray(n+1) {Int.MIN_VALUE}
    dp[0] = 0

    for(i in 1 .. n) {
        if(i-a>=0) {
            dp[i] = dp[i-a]+1
        }
        if(i-b>=0) {
            dp[i] = maxOf(dp[i], dp[i-b]+1)
        }
        if(i-c>=0) {
            dp[i] = maxOf(dp[i], dp[i-c]+1)
        }
    }
    print(dp[n])
}