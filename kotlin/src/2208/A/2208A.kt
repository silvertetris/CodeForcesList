fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = Array(n) {br.readLine().split(" ").map{it.toInt()}.toIntArray()}
        val cnt = IntArray(10001) {0}
        for(i in 0 until n) {
            for(j in 0 until n) {
                cnt[a[i][j]]++
            }
        }
        if(cnt.max()> n*(n-1)) {
            bw.write("NO\n")
        } else bw.write("YES\n")
    }
    bw.flush()
}