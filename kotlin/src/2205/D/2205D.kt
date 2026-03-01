fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()

        val del = IntArray(n) { 0 }
        val stk = IntArray(n)
        var ans = n

        var top = 0
        for (i in 0 until n) {
            while (top > 0 && a[stk[top - 1]] < a[i]) {//감소하는 배열 (stk)
                top--
            }
            stk[top++] = i
            del[i] += (i + 1) - top //탐색 과정에서 이 인덱스 기준으로 삭제해야하는 총 원소 갯수 -> 감소하는 배열을 만족하기 위해서
        }

        top = 0
        for (i in n - 1 downTo 0) {
            while (top > 0 && a[stk[top - 1]] < a[i]) {
                top--
            }
            stk[top++] = i
            del[i] += (n - i) - top
        }

        for (i in 0 until n) {
            ans = minOf(ans, del[i])
        }

        bw.write("${ans}\n")
    }
    bw.flush()
}