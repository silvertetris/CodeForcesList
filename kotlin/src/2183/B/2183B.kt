fun main() {
    val br =System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(n, k) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }.sorted()
        var ans = -1
        var cnt = 0
        for(i in 0 until n) {
            if(cnt==k-1) {
                break
            }
            if(ans+1 == a[i]) {
                ans = a[i]
                cnt++
            }
        }
        bw.write("${ans+1}\n")
    }
    bw.flush()
}