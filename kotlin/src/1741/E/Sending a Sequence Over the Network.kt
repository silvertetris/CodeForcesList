import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val bw = System.out.bufferedWriter()

    val t = sc.nextLine().toInt()
    repeat(t) {
        val n = sc.nextLine().toInt()
        val b= IntArray(n+1)
        for(i in 1..n) {
            b[i] = sc.nextInt()
        }
        // 1. states / sub problems
        val dp = BooleanArray(n+1) { false }
        //2. Base Cases
        dp[0] = true

        //3. transition
        for (i in 1 .. n) {
            if(i-b[i]-1 >=0) { // if the size of the last segment is in the last index
                if(dp[i-b[i] -1]) {
                    dp[i] = true
                }
            }
            if(dp[i-1]) { //if the last segment's size is in its left
                if(i+b[i] <=n) {
                    dp[i + b[i]] = true
                }
            }
        }
        //4. final answer
        if(dp[n]) {
            bw.write("YES\n")
        }
        else {
            bw.write("NO\n")
        }
        sc.nextLine()
    }
    bw.flush()
    bw.close()
}