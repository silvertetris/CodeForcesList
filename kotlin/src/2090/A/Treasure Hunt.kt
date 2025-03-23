fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(x, y, a) = br.readLine().split(" ").map{it.toInt()}
        val temp1 = a%(x+y)
        //결국에 a 보다 초과해야함
        //k가 x가 파면 no, y 가 파면 yes
        if(temp1-x<0) {
            bw.write("NO\n")
        } else {
            bw.write("YES\n")
        }
    }
    bw.flush()
    bw.close()
}