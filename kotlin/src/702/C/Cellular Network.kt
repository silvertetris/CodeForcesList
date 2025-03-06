fun main () {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val(n, m) = br.readLine().split(" ").map { it.toInt() }
    val a = br.readLine().split(" ").map { it.toInt() } //cities coordinates
    val b= br.readLine().split(" ").map { it.toInt() } //towers coordinates
    var result = 0
    for(i in 0 until n) {
        var l = 0
        var r = m-1
        while(l<=r) {
            val mid = (l+r)/2
            if(b[mid] <= a[i]) {
                l = mid +1
            }
            else {
                r = mid-1
            }
        }
        var d = Int.MAX_VALUE
        l-=1
        if(l>=0) d = minOf(d, a[i] - b[l]) //좌측에 있을 경우
        if(l<m-1) d = minOf(d, b[l+1] - a[i]) //우측에 있을 경우

        result= maxOf(result, d)
    }
    bw.write("$result")
    bw.flush()
    bw.close()
}