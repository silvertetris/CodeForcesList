fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val s = br.readLine()
    val q = br.readLine().toInt()
    val cnt = Array(s.length+1) { Triple(0, 0, 0) } //B, S, G
    for (i in 1 .. s.length) {
        if (s[i-1] == 'B') {
            cnt[i] = Triple(cnt[i - 1].first + 1, cnt[i - 1].second, cnt[i - 1].third)
        } else if (s[i-1] == 'S') {
            cnt[i] = Triple(cnt[i - 1].first, cnt[i - 1].second + 1, cnt[i - 1].third)
        } else {
            cnt[i] = Triple(cnt[i - 1].first, cnt[i - 1].second, cnt[i - 1].third + 1)
        }
    }

    repeat(q) {
        val (l, r) = br.readLine().split(" ").map { it.toInt() }
        val arr = IntArray(3) { 0 }
        arr[0] = cnt[r].first - cnt[l - 1].first
        arr[1] = cnt[r].second - cnt[l - 1].second
        arr[2] = cnt[r].third - cnt[l - 1].third
        arr.sortDescending()
        bw.write("${arr[0] + arr[2]}\n")
    }
    bw.flush()
    bw.close()
}