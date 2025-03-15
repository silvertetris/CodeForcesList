fun main() {
    val MOD = 1000000007
    val br = System.`in`.bufferedReader()
    val (r, g) = br.readLine().split(" ").map { it.toInt() }
    var h = 1
    val n = 200015
    val cnt = IntArray(n)
    cnt[0] = 1 //높이가 0일경우 경우의 수는 1임

    while (h * (h + 1) / 2 <= r + g) {
        for (i in n - 1 downTo h) { //last row 가 i만큼 블록을 차지할 때
            cnt[i] = (cnt[i] + cnt[i - h]) % MOD
        }
        h++
    }
    h--

    var ans = 0
    for (i in 0..r) {
        if (h * (h + 1) / 2 - i <= g) {
            ans = (ans + cnt[i]) % MOD
        }
    }

    print(ans)
}