fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val d = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        val li = IntArray(n) {0}
        val ri = IntArray(n) {0}
        for(i in 0 until n) {
            val temp = br.readLine().split(" ").map { it.toInt() }.toIntArray()
            li[i] = temp[0]
            ri[i] = temp[1]
        }
        var left = 0
        val last = mutableListOf<Int>()
        for(i in 0 until n) {
            if(d[i]==-1) {
                last.add(i) //인덱스를 더함
            } else {
                left+=d[i] //좌 기준으로 일때 높이 더함
            }
            while(left<li[i]) { //각 상황 가정
                if(last.isEmpty()) { //추가할게 없는데 조건이 만족 못하면 안되는 배열임
                    bw.write("-1\n")
                    return@repeat
                }
                d[last.last()]=1//백트레킹
                left++
                last.removeLast()
            }
            while(left+last.size>ri[i]) {
                if(last.isEmpty()) {
                    bw.write("-1\n")
                    return@repeat
                }
                d[last.last()]=0
                last.removeLast()
            }
            if(d[i]==-1) {
                d[i] = 0
            }
        }
        bw.write("${d.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
}