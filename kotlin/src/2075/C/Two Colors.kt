fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()

        for (i in a.indices) { //경우의 수의 최대 가질 수 있는 수는 n-1임
            if (a[i] == n) a[i]--//n이면 경우의 수 초과가남 -> 하나 줄여줌 (최소 두가지 색으로 칠해야 하니까)
        }

        a.sort()

        val s = LongArray(m + 1)
        for (i in m - 1 downTo 0) { //suffixSum
            s[i] = s[i + 1] + a[i]
        }

        var ans = 0L
        for (i in 0 until m) {
            var l = i + 1
            var r = m - 1

            while (l <= r) {
                val mid = (l + r) / 2
                if (a[mid] + a[i] >= n) {
                    r = mid - 1
                } else {
                    l = mid + 1
                }
            }
            ans += s[l] + (m - l) * (a[i] - n + 1).toLong() //경우의 수 점화식 -> 이는 조합론에서 직접 생각해야함
        }

        bw.write("${2 * ans}\n")
    }
    bw.flush()
    bw.close()
}