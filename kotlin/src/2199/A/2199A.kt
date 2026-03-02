fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val k = br.readLine().toInt()
        val(a1, b1) = br.readLine().split(" ").map { it.toInt() }//왼이 엘리스 -> 밥이 이길 수 있으면 yes 아니면 no
        val(a2, b2) = br.readLine().split(" ").map { it.toInt() }
        var round = 0
        if(a1<b1) {
            round++
        }
        if(a2<b2) {
            round++
        }
        var alice = a1+ a2
        var bob = b1+b2
        bob+=k
        round++
        if(alice<bob || (alice==bob && round>=2)) {
            bw.write("YES\n")
        } else {
            bw.write("NO\n")
        }
    }
    bw.flush()
}