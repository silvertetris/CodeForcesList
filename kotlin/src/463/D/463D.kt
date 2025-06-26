fun main() {
    val br = System.`in`.bufferedReader()
    val(n, k) = br.readLine().split(" ").map { it.toInt() }
    val arr = Array(k) {IntArray(n) }
    val pos = Array(k) {IntArray(n+1)}
    for(i in 0 until k) {
        arr[i] = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        for(j in 0 until n) {
            pos[i][arr[i][j]] = j
        }
    }
    val dp = IntArray(n) {1} //dp[i] = i 인덱스에서 공통되는 마지막 요소

    for(i in 0 until n) {
        for(j in 0 until i) {
            var flag = true
            for(p in 0 until k) {
                if(pos[p][arr[0][i]]<pos[p][arr[0][j]]) {// 하나를 기준으로 잡고 하나라도 앞에 있어야하는 게 없으면 false임
                    flag = false
                }
            }
            if(flag) { //공통중에 마지막 요소니까
                dp[i] = maxOf(dp[i], dp[j]+1)
            }
        }
    }
    print(dp[1])
}