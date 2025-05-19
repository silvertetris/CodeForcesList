fun main() {
    val br = System.`in`.bufferedReader()
    val bw= System.`out`.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt() }
        if(a.count{it==0}<1) {
            bw.write("YES\n")
            return@repeat
        }
        for(i in 1 until n) {
            if(a[i]==0 && a[i-1]==0) {
                bw.write("YES\n")
                return@repeat
            }
        }
        bw.write("NO\n")
    }
    bw.flush()
    bw.close()
}