fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt()}.toMutableList()
        val resultPair = ArrayList<Pair<Int, Int>> ()
        var k = 0
        var l = 0
        var r = n-1
        var temp = false
        for(i in n-1 downTo 0) {
            if(i==0 && a[i] ==0) {
                l=i
                r = i+1
                resultPair.add(Pair(l+1, r+1))
                k++
                continue
            }
            if(a[i] == 0) {
                if(temp) {
                    l = i
                    temp = false
                    resultPair.add(Pair(l+1, r+1))
                    k++
                    continue
                }
                r=i
                temp = true
            }
            if(a[i] !=0) {
                if(temp) {
                    l = i
                    temp = false
                    resultPair.add(Pair(l+1, r+1))
                    k++
                }
            }
        }
        resultPair.add(Pair(1, n-k))
        k++
        bw.write("$k\n")
        for(i in 0 until resultPair.size) {
            bw.write("${resultPair[i].first} ${resultPair[i].second}\n")
        }
    }
    bw.flush()
    bw.close()
}