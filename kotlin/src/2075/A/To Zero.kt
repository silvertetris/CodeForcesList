fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        var(n, k) = br.readLine().split(" ").map { it.toInt() }
        var answer = 0
        if(n%2!=0) {
            if(k%2!=0 ) {
                n-=k
                answer++
                answer +=n/(k-1)
                if(n%(k-1)!=0) {
                    answer ++
                }
            }
        } else {
            if(k%2!=0) {
                answer = n/(k-1)
                if(n%(k-1)!=0) {
                    answer ++
                }
            }else {
                answer = n/k
                if(n%k!=0) {
                    answer ++
                }
            }
        }
        bw.write("$answer\n")
    }
    bw.flush()
    bw.close()
}