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
            qDiv[i] = a[i] % q % p
            pDiv[i] = a[i] % p % q
        }
        if (n < k) {
            var result = 0L
            for (i in 0 until n) {
                result += a[i]
            }
            bw.write("$result\n")
            return@repeat
        }
        //sliding window -> 앞구간 먼저 해놓고 뒤에 작은순, 뒤구간 먼저해놓고 앞에 작은순 비교
        /*
        서로 다르게 오차 누적이 발생하는 것을 더해줌
        더해줘서 k이후로 탐색할때 슬라이딩 읜도우
        front는 p로 잡을때
        그 누적으로 잡은게 윈도우 밀면서 더 크면 초기화 시켜줌
         */
        var frontres: Long
        var endres: Long
        var frontsum = 0L
        var endsum = 0L
        var baseSum = 0L
        for (i in 0 until n) {
            baseSum += minOf(qDiv[i], pDiv[i])
        }
        for (i in 0 until k) {
            frontsum += pDiv[i] -minOf(pDiv[i], qDiv[i])
            endsum += qDiv[i] - minOf(pDiv[i], qDiv[i])
        }
        frontres = frontsum
        endres = endsum
        //여기서 나온 i뒤를 더해줘야함
        for(i in k until n) {
            frontsum = frontsum - (pDiv[i-k] -minOf(pDiv[i-k], qDiv[i-k])) + pDiv[i] - minOf(pDiv[i], qDiv[i])
            if(frontsum<frontres) {
                frontres = frontsum
            }

            endsum = endsum-(qDiv[i-k] -minOf(pDiv[i-k], qDiv[i-k]) ) + qDiv[i] - minOf(qDiv[i], pDiv[i])
            if(endsum<endres) {
                endres = endsum
            }
        }
        bw.write("${baseSum+minOf(frontres,endres)}\n")
    }
    bw.flush()
}