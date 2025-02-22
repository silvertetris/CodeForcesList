import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val arr = br.readLine().split(" ").map { it.toInt() }
    val mem = LongArray(100001)
    val ans = LongArray(100001)
    //count init (메모리제이션 기법)
    for (i in 0 until n) {
        mem[arr[i]]++
    }
    //base case
    ans[0] = 0
    ans[1] = mem[1]


    /*
    1. find out the states/ subproblems

states: maximum score when maximum element is i
최대 값을 i 로 잡고 1부터 i 가지의 범위로 지정함
i 이후에 모든 값들은 다 ignore
-> dp[i]
     */
    for (i in 2..arr.max()) {
        ans[i] = max(ans[i - 1], mem[i] * i + ans[i - 2])
    }

    print(ans[arr.max()])
}