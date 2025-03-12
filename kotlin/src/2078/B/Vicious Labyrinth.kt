fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t= br.readLine().toInt()
    repeat(t) {
        val(n, k) = br.readLine().split(" ").map { it.toInt() }//칸 개수, 모든 사람이 텔타야하는 횟수
        if(n == 2) {
            bw.write("2 1\n")
        }
        else {
            if(k%2==1) {
                for(i in 0 until n-1) {
                    bw.write("$n ")
                }
                bw.write("${n-1}\n")
            } else {
                for(i in 0 until n-2) {
                    bw.write("${n-1} ")
                }
                bw.write("$n ")
                bw.write("${n-1}\n")
            }
        }
    }
    bw.flush()
    bw.close()
}