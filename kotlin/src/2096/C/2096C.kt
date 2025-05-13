private const val INF = 1e18.toLong()

fun solveHor(n: Int, h: Array<IntArray>, a: IntArray): Long {
    /*
    #1. dp[i][j]
    i번째 열에서 j 과정 수행
    j==0 : 연산을 하지 않을 때 최소 비용
    j==1 : 연산을 했을 때 최소 비용
     */
    val dp = Array(n) { LongArray(2) { INF } } //min값을 구함으로 불가능하면 INF 도출
    //#2. Base Cases
    dp[0][0] = 0L
    dp[0][1] = a[0].toLong()

    for (i in 1 until n) {
        for (x in 0..1) {//현재 연산을 할거냐 말거냐
            for (y in 0..1) {//그전 열이 연살을 했냐 안했냐
                var ok = true
                for (j in 0 until n) {
                    //각 경우의 수에 대해서 같으면 이 경우는 안됨
                    if (h[i - 1][j] + y == h[i][j] + x) ok = false
                }
                //#3. transitions
                if (ok) { //x, y 에 대해서 해당 연산을 진행 했을 때 가능한 경우 -> dp 연산
                    if (x == 0) {
                        dp[i][x] = minOf(dp[i][x],dp[i - 1][y])//최대값 제한
                        /*
                        same as
                        if(dp[i][x]>dp[i-1][y]) {
                            dp[i][x] = dp[i-1][y]) } else{
                            dp[i][x] = dp[i][x]}
                         */
                    }
                    if (x == 1) {
                        dp[i][x] = minOf(dp[i][x],dp[i - 1][y] + a[i])
                    }
                }
            }
        }
    }
    //#4. final answer
    return minOf(dp[n - 1][0], dp[n - 1][1])
}

//수직, 수평 모두 계산하기 위해 전치행렬 -> 코드 duplicate 방지
fun transpose(n: Int, h: Array<IntArray>) {
    for (i in 0 until n) {
        for (j in i + 1 until n) {
            val tmp = h[i][j]
            h[i][j] = h[j][i]
            h[j][i] = tmp
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val h = Array(n) { br.readLine().split(" ").map { it.toInt() }.toIntArray() }
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        val b = br.readLine().split(" ").map { it.toInt() }.toIntArray()

        val horCost = solveHor(n, h, a)
        transpose(n, h)
        val verCost = solveHor(n, h, b)
        val totalCost = horCost + verCost //수직 수평 연산 둘다 더해줌

        if (totalCost >= INF) {
            bw.write("-1\n")
        } else {
            bw.write("$totalCost\n")
        }
    }
    bw.flush()
    bw.close()
}