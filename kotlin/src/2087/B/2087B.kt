fun main() {
    val br=System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt() }.sorted()
        for(i in 0 until 2*n step 2) {
            val sub = a[i+1]-a[i]
            if(i>=2) {
                if(a[i]-a[i-1]<sub) {
                    bw.write("NO\n")
                    return@repeat
                }
            }
            if(i<=2*n-3) {
                if(a[i+2]-a[i+1]<sub) {
                    bw.write("NO\n")
                    return@repeat
                }
            }
        }
        bw.write("YES\n")
    }
    bw.flush()
    bw.close()
}