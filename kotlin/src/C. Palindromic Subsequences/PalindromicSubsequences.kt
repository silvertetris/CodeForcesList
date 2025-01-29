fun main() {
    val n = readln().toInt()
    val result:ArrayList<Array<Int>> = ArrayList(n)

    for( i in 0 until n) {
        val input = readln().toInt()
        var arr:Array<Int> = Array(input) {input}
        result.add(arr)
    }
    for(i in 0 until n) {
        println(result[i].joinToString(" "))
    }
}