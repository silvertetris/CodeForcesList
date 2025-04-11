fun main() {
    val br = System.`in`.bufferedReader()
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    val arr = Array(n) {CharArray(m)}
    for(i in 0 until n) {
        arr[i] = br.readLine().toCharArray()
    }

}