fun main() {
    val t = readln().toInt()
    repeat(t) {
        val (n, x) = readln().split(" ").map { it.toInt() }

        val result = mutableListOf<Int>()

        for (i in 0 until n - 1) {
            result.add(i)
        }
        val orValue = result.fold(0) { acc, num -> acc or num }
        val lastElement = x or orValue
        result.add(lastElement)

        println(result.joinToString(" "))
    }
}