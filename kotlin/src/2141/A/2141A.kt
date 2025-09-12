fun main () {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        val answer = mutableListOf<Int>()
        var last = a[0]
        var cnt = 0
        for(i in 1 until n) {
            if(last<a[i]) {
                cnt++
                answer.add(i+1)
            } else {
                last = a[i]
            }
        }
        bw.write("$cnt\n")
        bw.write("${answer.joinToString (" ") }\n")
    }
    bw.flush()
}