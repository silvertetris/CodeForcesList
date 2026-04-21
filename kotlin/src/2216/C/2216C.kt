import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val str = StringTokenizer(br.readLine())
        val str2 = StringTokenizer(br.readLine())
        val n = str.nextToken().toInt()
        val k = str.nextToken().toInt()
        val p = str.nextToken().toInt()
        val q = str.nextToken().toInt()
        val a = IntArray(n)
        for (i in 0 until n) {
            a[i] = str2.nextToken().toInt()
        }
        val pDiv = IntArray(n)
        val qDiv = IntArray(n)
        for (i in 0 until n) {
            qDiv[i] = a[i]%q
            pDiv[i] = a[i]%p
        }
        if(n<k) {
            bw.write("${a.sum()}\n")
        }
        //sliding window
        var front = 0L
        var end=0L
        var frontMin = 0L
        var endMin = 0L
        for(i in 0 until k-1) {
            frontMin+=pDiv[i]
            endMin+=qDiv[i]
        }
        front+= minOf(frontMin, endMin)
        for(i in 0+k-1 until n) {
            front+=minOf(qDiv[i], pDiv[i])
        }
        frontMin=0
        endMin=0
        for(i in n-1 downTo n-k+1) {
            frontMin+=qDiv[i]
            endMin+=pDiv[i]
        }
        end+=minOf(frontMin, endMin)
        for(i in n-k downTo  0) {
            end+=minOf(qDiv[i], pDiv[i])
        }
        bw.write("${minOf(front, end)}\n")
        /*
        틀린이유
        중간지점을 qDiv로 나눈 후에, pDiv로 중복 나누면 수가 더 적어질 수 있음
        
         */
    }
    bw.flush()
}