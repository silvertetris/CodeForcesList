fun main() {
    val t = readln().toInt()
    val result = StringBuilder()

    fun gcd(num1: Int, num2: Int): Int {
        val temp = num2 % num1
        if(temp ==0) {
            return num1
        }
        return gcd(temp, num1)
    }
    repeat(t) {
        val a = readln().split(" ").map { it.toInt() }.sorted()
        result.append("${a[0]*a[1]/gcd(a[0], a[1])}\n")
    }
    print(result)
}