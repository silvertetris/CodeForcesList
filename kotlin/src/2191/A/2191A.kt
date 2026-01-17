fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        var flag = false // false 면 홀수
        if(a[0]%2==0) flag = true
        for(i in 0 until n) {
            if(flag) {
                if(i%2==0 && a[i]%2==1) {
                    bw.write("NO\n")
                    return@repeat
                }
            }
            else {
                if(i%2==0 && a[i]%2==0) {
                    bw.write("NO\n")
                    return@repeat
                }
            }
        }
        bw.write("YES\n")
    }
    bw.flush()
}