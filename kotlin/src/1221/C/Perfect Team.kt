fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val q = br.readLine().toInt()
    repeat(q) {
        val (c, m, x) = br.readLine().split(" ").map { it.toInt() }
        val n = c + m + x
        var l = 0
        var r = n / 3
        while (l <= r) {
            var mid = (l + r) / 2
            if (mid <=c && mid <= m && 3 * mid <= n) { //다 가능한 수치일 때
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
        bw.write("${l-1}\n")
        /*
        l-1인 이유:
        답이 0인 경우가 의심스러운데 대입해봄
        1 0 2 일때
        n = 3
        r = 1
        mid = 0
        처음에는 조건이 만족됨
        mid: 0 <=c: 1, mid:0 <= 0 , 3*mid:0 <= 1
        그 후에 l이 1이됨
        l<=r이 조건에 맞으니 한번 더 반복문 돎
        l = 1
        r = 1
        mid = 1
        3 <= 1 에 의해 if 문 false -> r = 0 -> l은 이미 1이니까 -1 해주면 0 이됨.

        이것이 왜 가능한 것인가??
        -> 팀을 만드려면 if 문의 세가지 조건이 모두 맞아 떨어져야함
        처음에 불가능한데도 if문에 받아지는 이유?
        -> mid 의 정수를 2로 나누는 내림 특성 때문에 그럼
        -> l==r 조건이 true 기 때문에 한번 더 도는 것 따라서 l 이 1이 추가됨.
        -> 따라서 mid가 다른 값들과 같아도 한번 더 통과시키니까 저렇게 +1 된 상태로 정답이 나오는 것
         */
    }
    bw.flush()
    bw.close()
}