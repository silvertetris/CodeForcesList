fun main() {
    val br =System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(n, k) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }.sorted()
        if(a[0]!=0) {
            bw.write("0\n")
            return@repeat
        }
        for(i in 1 until k-1) {
            if(a[i]-a[i-1]>1) {
                bw.write("${a[i-1]+1}\n")
                return@repeat
            }
        }
        bw.write("${a[k-1]+1}\n")
    }
    bw.flush()
}