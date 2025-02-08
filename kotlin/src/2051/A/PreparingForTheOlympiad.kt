fun main() {
    val t = readln().toInt()
    var result = StringBuilder()
    repeat(t) {
        val n = readln().toInt()
        var a = readln().split(" ").map { it.toInt() }
        var b = readln().split(" ").map { it.toInt() }
        var cnt = 0
        for(i in 0 until n-1) {
            if(a[i]-b[i+1]>0) {
                cnt+=a[i]-b[i+1]
            }
        }
        cnt+=a[n-1]
        result.append("$cnt\n")
    }
    print(result)
}