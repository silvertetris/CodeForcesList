import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    val a = br.readLine().split(" ").map { it.toLong() }
    val b = br.readLine().split(" ").map { it.toLong()}
    fun gcd (a: Long, b: Long): Long{
        return if(b==0L) a else gcd(b,a%b)
    }
    var x = 0L
    for(i in 1 until n) {
        x = gcd(x, abs(a[i]-a[0]))
    }
    for(i in 0 until m) {
        bw.write("${gcd(a[0]+b[i], x)} ")
        //gcd(a[i]+b[j], a[i]+b[j]-(a[i+1]+b[j]))
        //뒷 항들은 결국 위 식과 같아짐으로 a의 gcd와 같음
    }
    bw.flush()
    bw.close()
}