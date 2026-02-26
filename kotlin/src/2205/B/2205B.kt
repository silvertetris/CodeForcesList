fun main() {
    val br= System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    //소수 판정 문제 -> 약수분해
    val isPrime = BooleanArray(31624) {true}
    isPrime[0] = false
    isPrime[1] = false
    for(i in 2..31623) {
        if(!isPrime[i]) continue
        for( j in i*i..31622 step i) {
            isPrime[j] = false
        }
    }
    val primes = mutableListOf<Int>()
    for(i in isPrime.indices) {
        if(isPrime[i]) primes.add(i)
    }
    repeat(t) {
        var n = br.readLine().toInt()
        var ans = 1
        //소인수로 초대한 나누지 않음
        for(i in primes) {
            if(i*i >n) break
            if(n%i==0) {
                ans*=i
                while(n%i==0) {
                    n/=i
                }
            }
        }
        if(n>1) ans*=n
        bw.write("$ans\n")
    }
    bw.flush()
    bw.close()
}