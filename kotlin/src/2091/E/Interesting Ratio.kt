fun main() {
    /*
    서로 다른짝이 얼마나 있는지
그니까 최소공배수 / 최대공약수 가 소수여야함
1 3
1 2
1 5
2 4

3 6
그니까 소수의 배수 / 소수 = 소수 여야함
그래야 만족


     */
    val br = System.`in`.bufferedReader()
    val t = br.readLine().toInt()
    fun protossteness(n: Int): MutableList<Int> {
        val isPrime = BooleanArray(n + 1) { true }
        isPrime[0] = false
        isPrime[1] = false
        for (i in 2..Math.sqrt(n.toDouble()).toInt()) {
            if (isPrime[i]) {
                for (j in i * i..n step i) {
                    isPrime[j] = false
                }
            }
        }
        val primes = mutableListOf<Int>()
        for (i in 2..n) {
            if (isPrime[i]) {
                primes.add(i)
            }
        }

        return primes
    }

    val ns = Array(t) { 0 }
    for (i in 0 until t) {
        ns[i] = br.readLine().toInt()
    }
    val max = ns.max()
    val primes = protossteness(max)

    for (n in ns) {
        var cnt = 0
        for (p in primes) {
            if (p > n) break
            cnt += n / p
        }
        println(cnt)
    }
}

