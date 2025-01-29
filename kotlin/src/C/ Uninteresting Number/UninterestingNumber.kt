fun main() {
    val n = readln().toInt()
    val result: StringBuilder = StringBuilder()
    repeat(n) {
        var input = readln()
        if (input.toLong() % 9 == 0L) {
            result.append("YES\n")
        }
    }
}