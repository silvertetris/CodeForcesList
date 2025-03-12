fun main() {
    val t = readln().toInt()
    for (i in 0 until t) {
        val (n, x) = readln().split(" ").map { it.toInt() }
        val a = readln().split(" ").map { it.toInt() }
        if (n == 1) {
            if (a[0] == x) {
                println("YES")
            } else {
                println("NO")
            }
        } else {
            val sum = a.sum()
            val average = sum.toDouble() / n.toDouble()
            if (average == x.toDouble()) {
                println("YES")
            } else {
                println("NO")
            }
        }
    }
}