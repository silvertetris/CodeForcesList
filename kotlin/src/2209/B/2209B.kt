fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a= br.readLine().split(" ").map { it.toInt() }.toIntArray()
        //그냥 뒤에 작은거 와 큰거 개수중 뭐가 더 많은지 세는듯
        for(i in 0 until n) {
            var big = 0
            var small = 0
            for(j in i+1 until n) {
                if(a[i]>a[j]) {
                    big++
                }
                else if(a[i]<a[j]) {
                    small++
                }
            }
            bw.write("${maxOf(big, small)} ")
        }
        bw.write("\n")
    }
    bw.flush()
    bw.close()
}