fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val (n, m, l) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        val fred = mutableListOf<Int>()
        for (i in 0 until minOf(n + 1, m)) {
            fred.add(0)
        }
        var ans = l
        var left = n
        for (i in 1 ..l) {
            fred.sort()
            val cur = fred.first()
            fred.removeFirst()
            fred.add(cur + 1)
            if (a.binarySearch(i)>=0) {
                fred.sort()
                ans-=fred.last()
                fred.removeLast()
                if(fred.size<left) {
                    fred.add(0)
                }
                left-=1
            }
        }
        bw.write("$ans\n")
    }
    bw.flush()
    bw.close()
}