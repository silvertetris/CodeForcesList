import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, q) = br.readLine().split(" ").map { it.toInt() }
    val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
    val x = br.readLine().split(" ").map { it.toLong() }.toLongArray()
    /*
    1차이나면서 부분배열
    -> 그니까 특정 a 기준에서 우로 탐색할때, 더 크면 1씩 크게 사이에 숫자를 넣어야하고 작으면 1씩 작게 -> 상승 감소 상승감소 반복 가능성
    -> 그렇다고 직접 넣으면 tle무조건 나오니까 계산을 때려야함
    0이 나오는 경우는 같은 두 수가 연속적이고
    크기는 정해져있음-> 일단 각 수에 대한 차를 사이즈에 대해 더해줌
    -ideal
    1. 인덱스는 long 수 -> 크니까 인덱스 찾는건 이분탐색으로 진행 -> 그 후에 일일히 찾기 ->
    2. 그리디 best 기법 쓰기 -> 한번에 탐색
     */
    //각 원소들이 완성된 배열이 어느 index 인지 -> 각 인덱스의 사이값을 이분탐색 value의 사이값
    val pos = LongArray(n) { 0 }
    pos[0] = 1
    for (i in 0 until n - 1) {
        pos[i + 1] = if (a[i + 1] - a[i] == 0) pos[i] + 2L else pos[i] + abs(a[i + 1] - a[i])
    }

    for (i in 0 until q) {
        if (x[i] > pos[n - 1]) {
            bw.write("-1 ")
        } else {
            var l = 0
            var r = n - 1
            while (l < r) {
                val mid = (l + r + 1) / 2//x[i] 는 1based
                if (pos[mid] <= x[i]) {
                    l = mid
                } else {
                    r = mid - 1
                }
            }
            val idx = l
            var ans = 0L
            if (pos[idx] == x[i]) {
                ans = a[idx].toLong()
            } else {
                val curv = a[idx + 1] - a[idx]
                val temp = x[i] - pos[idx]
                /*
                1 1 -> 0 or 차이 있을 경우
                -> 아닌놈일 경우
                 */
                if (curv == 0) {
                    if (temp == 1L) {//바로 옆에 똑같은 놈 있을 경우
                        ans = 0
                    } else {
                        ans = a[idx].toLong()
                    }
                } else {
                    if (curv < 0) {
                        ans = a[idx] - temp
                    } else {
                        ans = a[idx] + temp
                    }
                }

            }
            bw.write("$ans ")
        }
    }
    bw.flush()
}