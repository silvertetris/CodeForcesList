fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val s = br.readLine()//color
        val a = br.readLine().split(" ").map { it.toInt() } // penalty
        var l = 0
        var r = a.max()
        while (l <= r) { //우리가 탐색하는 기준은 penalty max(min)
            val mid = (l + r) / 2
            var nk = k //남은 k 값
            var lst = false//그냥 포함시켜도 될지에 대한 불린
            for (i in 0 until n) {
                if (a[i] > mid && s[i] == 'R') {//lst 가 false 인순간 칠해야함
                    lst = false
                } else if (a[i] > mid && s[i] == 'B') {
                    if (!lst) {
                        nk -= 1
                        lst = true
                    } else { //작으면 무시해도 되니까 횟수를 줄이지 않고 nk-=1
                        lst = true
                    }
                }
            }
            if (nk >= 0) {
                r = mid - 1
            } else {
                l = mid + 1
            }
        }
        bw.write("$l\n")
    }
    bw.flush()
    bw.close()
}