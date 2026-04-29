import java.util.StringTokenizer

fun main() {
    val br  = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    /*
    n+1 -(i+1) = a[i]
    그니까 어떤 수를 먼저 연산을 진행하느냐에 따라
    뒤에 붙은 0에서의 연산이 가능해짐
    문제 -> 중간지점에서 골라도 최대값이 만들어질 수 있음
     */
    repeat(t) {
        val n = br.readLine().toInt()
        val str= StringTokenizer(br.readLine())
        val a = LongArray(n)
        for(i in 0 until n) {
            a[i] = str.nextToken().toLong()
        }
        val uDp = LongArray(n) {0L}
        val dDp = LongArray(n) {0L}
        uDp[0] = n.toLong()
        dDp[n-1] = n.toLong()
        for(i in 1 until n) {
            uDp[i] = uDp[i-1]
            if(a[i] == uDp[i]+1 - (i+1)) {
                uDp[i]+=i.toLong()
            }
        }
        for(i in n-2 downTo 0) {
            dDp[i] = dDp[i+1]
            if(a[i] == dDp[i]+1 - (i+1)) {
                dDp[i]+=i.toLong()
            }
        }
        bw.write("${maxOf(dDp[0], uDp[n-1])}\n")
    }
    bw.flush()
}