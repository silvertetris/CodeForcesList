fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val left = br.readLine().split(" ").map { it.toInt() }
        val right = br.readLine().split(" ").map { it.toInt() }
        val a = IntArray(n) { 0 }
        val b = IntArray(n) { 0 }
        var ans = 0L
        for (i in 0 until n) {
            a[i] = maxOf(left[i], right[i])
            b[i] = minOf(left[i], right[i])
            ans += a[i] //한쪽만 뽑을 최악의 수 -> 매칭되는 페어 = 0
        }
        //이제 매칭되게 해줘야함
        b.sortDescending()
        for (i in 0 until k - 1) {
            ans += b[i] //k-1 개가 무조건 매칭될 장갑 수 (최악의 수)
        }
        ans++ //이제 어떤 장갑을 뽑던 간에 하나의 색이 일치 됨
        bw.write("$ans\n")
    }
    bw.flush()
    bw.close()
}