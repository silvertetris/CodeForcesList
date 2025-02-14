fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val(n, m) = br.readLine().split(" ").map { it.toInt() }
        var arr:Array<IntArray> = Array(n) {IntArray(m) }
        for(i in 0 until n) {
            arr[i] = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        }
        //sum 으로 먼저 정렬 후, a[i] 랑 b[i]랑 다르면 더 큰놈이 먼저오게 정렬
        arr.sortWith(compareByDescending<IntArray> { it.sum() }.thenComparator { a, b ->
            for (i in a.indices) {
                if (a[i] != b[i]) {
                    return@thenComparator b[i].compareTo(a[i])
                }
            }
            0
        })
        var cnt = n*m
        var result =0L
        for(i in 0 until n) {
            for(j in 0 until m) {
                result+=arr[i][j].toLong()*cnt.toLong()
                cnt--
            }
        }
        bw.write("$result\n")
    }
    bw.flush()
    bw.close()
}