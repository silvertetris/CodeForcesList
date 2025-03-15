import java.math.BigInteger

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val s = br.readLine()
    val a = br.readLine().split(" ").map { it.toInt() }
    /*
    #1. states / subproblems
    dp[i][0] = 어떠한 subsequence 도 통과시키지 않으려할 때
    dp[i][1] = 'h' 까지만 통과시키고 나머지는 통과시키지 않을 때
    dp[i][2] = 'ha' 까지만 통과시키고 나머지는 통과시키지 않을 때
    dp[i][3] = 'har' 까지만 통과시키고 나머지는 통과시키지 않을 때
     */
    val dp = Array(n+1) {Array<BigInteger>(4) {BigInteger.ZERO} }
    //#2. Base Cases
    dp[0][0] = BigInteger.ZERO
    dp[0][1] = 99824435300000.toBigInteger()
    dp[0][2] = 99824435300000.toBigInteger()
    dp[0][3] = 99824435300000.toBigInteger()

    //#3. transitions
    for(i in 1 .. n) {
        if(s[i-1] =='h') {
            dp[i][0] = dp[i-1][0] + a[i-1].toBigInteger()//h를 뺌
            dp[i][1] = minOf(dp[i-1][0], dp[i-1][1])//h를 뺀거, a를 뺀거 중 min()
            dp[i][2] = dp[i-1][2]// 나머지는 관계없으니까 그대로 딸려옴
            dp[i][3] = dp[i-1][3]
        } else if(s[i-1] =='a') {
            dp[i][0] = dp[i-1][0]
            dp[i][1] = dp[i-1][1] + a[i-1].toBigInteger()
            dp[i][2] = minOf(dp[i-1][1], dp[i-1][2])
            dp[i][3] = dp[i-1][3]
        }
        else if(s[i-1] == 'r') {
            dp[i][0] = dp[i-1][0]
            dp[i][1] = dp[i-1][1]
            dp[i][2] = dp[i-1][2] + a[i-1].toBigInteger()
            dp[i][3] = minOf(dp[i-1][2], dp[i-1][3])
        }
        else if(s[i-1] == 'd') {
            dp[i][0] = dp[i-1][0]
            dp[i][1] = dp[i-1][1]
            dp[i][2] = dp[i-1][2]
            dp[i][3] = dp[i-1][3] + a[i-1].toBigInteger()
        }
        else {
            for(j in 0 until 4) {
                dp[i][j] = dp[i-1][j]
            }
        }
    }
    //#4. final answer
    bw.write("${minOf(dp[n][0], dp[n][1], dp[n][2], dp[n][3])}")
    bw.flush()
    bw.close()
}