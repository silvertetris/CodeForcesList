fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val cost = br.readLine().split(" ").map { it.toInt() }.sorted()
    val d = br.readLine().toInt()
    val m = IntArray(d)
    for( i in 0 until d) {
        m[i]= br.readLine().toInt()
        var l = 0
        var r = n-1
        var mid: Int
        while(l<=r) {
            mid=(l+r)/2
            if(cost[mid]<=m[i]) { //upper_bound 포함해도 최소 치를 올리니까
                l = mid+1
            }
            //while lower_bound increases only if cost[mid] < m[i]
            else {
                r = mid-1
            }
        }
        bw.write("${l}\n")
    }
    bw.flush()
    bw.close()
}