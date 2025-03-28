fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val (n, m, k) = br.readLine().split(" ").map { it.toLong() }
        var l = 1L
        var r = m
        var answer = r

        while (l <= r) {
            val mid = (l + r) / 2

            val temp = m / (mid + 1) //해당 블록의 수 (한 블록에 mid 칸일 때) -> +1 은 한칸 뛴거임
            val remain = m % (mid + 1) //뒤에 남은 칸 수 -> 이칸에 블록 추가로 배치해도 최대 길이가 안늘어남
            val max = temp * mid + remain //최대 블록수가 mid 일때 한줄에 놓을 수 있는 최대 녹색 수

            if (n * max >= k) { //토탈과 k 계산
                answer = mid
                r = mid - 1
            } else {
                l = mid + 1
            }
        }
        bw.write("$answer\n")
    }
    bw.flush()
    bw.close()
}
