import java.math.BigInteger

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    val INF = 10.toBigInteger().pow(18)
    /*
    #1. states / subproblems
    dp[i][j] = minimum cost of i digits in the end of the first num
               minimum cost of j digits in the end of the second num
     */
    val dp = Array(59) { Array<BigInteger>(59) { INF } }
    //#2. Base Cases
    dp[0][0] = 0.toBigInteger()

    //#3. Transition
    for (b in 1..57) {
        for (i in 58 downTo 0) {
            for (j in 58 downTo 0) {
                if (i >= b) dp[i][j] = minOf(dp[i][j], dp[i - b][j] + 1.toBigInteger().shiftLeft(b))
                if (j >= b) dp[i][j] = minOf(dp[i][j], dp[i][j - b] + 1.toBigInteger().shiftLeft(b))
            }
        }
    }
    repeat(t) {
        var ans = INF
        val (x, y) = br.readLine().split(" ").map { it.toBigInteger() }
        //#4. final answer
        for (i in 0..58) {
            for (j in 0..58) {
                if(dp[i][j] == INF) continue
                if (x.shiftRight(i) == y.shiftRight(j)) {
                    ans = minOf(ans, dp[i][j])
                }
            }
        }
        bw.write("${ans}\n")
    }
    bw.flush()
    bw.close()
}