fun main() {
/*
n 수평 레벨에 들어감
m개의 세그먼트로 나눔

고른 돌출부는 nxm 직사각형 공간이 됨

1. 첫 홀드는 가장 아래 n 행에 있음
2. 마지막 홀드는 가장 위 1 행에 있음
3. 각 부분 홀드는 전 홀드보다 낮지 않음
그니까 n 에서 1 이 오름차순이 아니란 말임
4. 한가지의 홀드가 무조건 이용 됨, 한 레벨에서
5. 최대 두 홀드가 각 레벨에서 이용 가능함
6. 각 홀드 센터 사이의 거리는 팔 거리를 능가하지 않음

이고르 파길이 = d
서로 다른 루트의 수
dp로 풀기
 */
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(n, m, d) = br.readLine().split(" ").map { it.toInt()}
        val dp = IntArray(n) {0}
        val arr = Array(n) {CharArray(m)}
        for(i in 0 until n) {
            arr[i] = br.readLine().toCharArray()
        }
        var valid = false
        for(i in 0 until m) {
            if(arr[0][i] == 'X') {
                dp[i] =1
            }
            else {
                valid = true
            }
        }
        if(!valid) {
            bw.write("0\n")
            return@repeat
        }

    }
}