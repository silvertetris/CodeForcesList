fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    n테스크 있음
c_i 값, p_i 엉려움
첫 스테미나 1
1부터 n 테스크

1. 포기하고 넘어간다
2. 완료한다, -> S * c_i 만큼 포인트, 하지만 클리어 후에 S*(1-p_i/100) 스테미나 떨어짐
최대 포인트

100나누는거 보니까 소수점 자리 있음 -> 그냥 아싸리 100곱해서 해도 됨 최대 100포임 각각
근데 혹시모르니까 10000곱하기 ㄱㄱ
아니다 근데 계속 계산하다보면 결국 소수점가니까 dp
근데 2차원하면 경우의 수가 많음
-> 스태미나는 제한적 없으면 못함 -> 미래 계산 백트래킹 dp

     */
    repeat(t) {
        val n = br.readLine().toInt()
        val c = IntArray(n+1) {0}
        val p = IntArray(n+1) {0}
        for(i in 1 .. n) {
            val(u, v) = br.readLine().split(" ").map { it.toInt() }
            c[i] = u
            p[i] = v
        }
        val dp = DoubleArray(n+2) {0.0}
        for(i in n downTo 1) {//#3. transitions -> skip, do it
            dp[i] = maxOf(dp[i+1], c[i].toDouble() + dp[i + 1] * (100.0 - p[i]) / 100.0)
        }
        //#4. final answer
        bw.write("${dp[1]}\n")
    }
    bw.flush()
}