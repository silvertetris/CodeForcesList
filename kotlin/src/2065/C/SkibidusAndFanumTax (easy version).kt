fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        var a = br.readLine().split(" ").map { it.toInt() }.toMutableList()
        val b = br.readLine().toInt()
        if(n==1) {
            bw.write("YES\n")
            return@repeat
        }
        if(a[0]>b-a[0]) {
            a[0] = b-a[0]
        }
        for(i in 1 until n) {
            if(a[i]<a[i-1]) {
                a[i]=b-a[i]
                continue
            }
            if(a[i-1]<=b-a[i] && a[i]>b-a[i]) {
                a[i]=b-a[i]
                continue
            }
        }
        if(a==a.sorted()){
            bw.write("YES\n")
        }
        else{
            bw.write("NO\n")
        }
    }
    bw.flush()
    bw.close()
}