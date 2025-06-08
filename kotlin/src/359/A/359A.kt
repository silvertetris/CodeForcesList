fun main() {
    val br = System.`in`.bufferedReader()
    val (n, x) = br.readLine().split(" ").map { it.toInt() }
    val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
    //x의 a_i 제곱들을 분모로 놓고 분자가 1인 것을 다 더해서 s/t로 만듦
    //약분하면 안됨 병렬 회로 구하듯이
    //이것의 gcd

}