import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    감소하지 않는 배열
    10^6까지 가장 큰 소수 저장
    각 수가 나뉠 수 있는 가장 큰 소수
    -> 이 아니라 작은 소수로 해야됨
     */
    val isPrime = BooleanArray(1000_001) { true }
    val minimize = IntArray(1000_001) { 1 }
    val maximize = IntArray(1000_001) {1}
    isPrime[0] = false
    isPrime[1] = false
    for (i in 2..1000_000) {
        if (isPrime[i]) {
            minimize[i] = i
            maximize[i] = i
            for (j in i + i..1000_000 step i) {
                if (minimize[j] == 1) {
                    minimize[j] = i
                }
                maximize[j] = i
                isPrime[j] = false
            }
        }

    }

    repeat(t) {
        val n = br.readLine().toInt()
        val str = StringTokenizer(br.readLine())
        val a = IntArray(n)
        for (i in 0 until n) {
            a[i] = str.nextToken().toInt()
        }
        /*
        조건 => 큰 소수를 밥이 앞에다가 배치할 가능성이 있으면 안됨
        엘리스가 먼저 시작하고 같으면서 증가배열 못만들면 엘리스승
        엘리스가 먼저 시작해도 증가배열 만들면 밥 승
         */
        if(a.sorted() == a.toList()) {
            bw.write("Bob\n")
            return@repeat
        }
        for(i in 0 until n) {
            if(minimize[a[i]] < maximize[a[i]]) {
                bw.write("Alice\n")
                return@repeat
            }
        }
        for(i in 1 until n) {//소수만 남으면
            if(maximize[a[i-1]]>maximize[a[i]]) {
                bw.write("Alice\n")
                return@repeat
            }
        }
        bw.write("Bob\n")
    }
    bw.flush()
}