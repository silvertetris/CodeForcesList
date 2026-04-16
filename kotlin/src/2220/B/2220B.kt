import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val str = StringTokenizer(br.readLine())
        val n = str.nextToken().toInt()
        val m = str.nextToken().toInt()
        val a = IntArray(n)
        val str2 = StringTokenizer(br.readLine())
        for (i in 0 until n) {
            a[i] = str2.nextToken().toInt()
        }
        var cnt = 1
        var flag = true
        for(i in 1 until n) {
            if(a[i-1] != a[i]) {
                cnt= 1
            } else {
                cnt++
            }
            if(cnt>=m) {
                flag = false
                break
            }
        }
        if(flag) {
            bw.write("YES\n")
        } else {
            bw.write("NO\n")
        }
    }
    bw.flush()
}