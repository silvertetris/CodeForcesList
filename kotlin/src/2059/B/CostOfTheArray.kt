fun main() {
    val t = readln().toInt()
    val result = StringBuilder()
    for(i in 0 until t) {
        val (n, k) = readln().split(" ").map { it.toInt() }
        val dif = n-k
        val a = readln().split(" ").map { it.toInt() }.toMutableList()
        if(n-k==0) {
            for(j in a.indices) {
                if(a[j]!=j+1) {
                    result.append("${j+1}\n")
                }
            }
        }
        else {
            for()
        }
    }
}