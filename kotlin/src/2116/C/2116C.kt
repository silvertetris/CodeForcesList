import java.util.*

fun main() {
    fun gcd(a: Int, b: Int): Int {
        return if (b == 0) a else gcd(b, a % b)
    }

    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(' ').map { it.toInt() }.toIntArray()
        a.sort()
        var entireGcd = a[0]
        for (i in 1 until n) {
            entireGcd = gcd(entireGcd, a[i])
        }

        val gcdDividedArr = a.map { it / entireGcd } //작은 값 기준 맞추기
        if (gcdDividedArr.any { it == 1 }) { // 1있으면 어차피 걔한테 맞춰야함
            bw.write("${gcdDividedArr.count { it != 1 }}\n")
        } else {
            //특정 인덱스 i 에 대해 가장 적은 연산을 가질 수 있는 수?? -> 결국 모든걸 1로 만드려는 생각을 ㄱㄱ
            //전체 최대 공약수를 1로 만드냐 아니면 모두가 공통되는 공약수로 만드나 -> 결국에 경우는 같음
            val dist = IntArray(5001) { -1 } //dist[1]로 만드는데 최소 거리 (연산 횟수) -> max(min)
            val queue: Queue<Int> = LinkedList()

            for (x in gcdDividedArr) { //각 나올 수 있는 최대 공약수에 대해서 경우의 수 구하기
                if (x <= 5000) {
                    if (dist[x] == -1) {
                        dist[x] = 0
                        queue.add(x)
                    }
                }
            }

            var bool = false
            while (queue.isNotEmpty() && !bool) {
                val cur = queue.poll()
                for (node in gcdDividedArr) {
                    val gcd = gcd(cur, node)
                    if (dist[gcd] == -1) { //계산횟수 +1 (나올 수 있는 최대 공약수가 아님) -> 이게 나오려면 계산을 최소 1번 더 해야함
                        dist[gcd] = dist[cur] + 1
                        queue.add(gcd)
                        if (gcd == 1) { //1 이 있는가? -> 1을 기준으로 잡고 연산
                            bool = true
                            break
                        }
                    }
                }
            }
            bw.write("${dist[1] + n - 1}\n")// max(min) + 개수들
        }
    }
    bw.flush()
    bw.close()
}