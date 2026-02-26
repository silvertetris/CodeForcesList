fun main() {
    val br= System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val p = br.readLine().split(" ").map{it.toInt()}.toIntArray()
        var maxIdx = p.indexOf(p.max())
        var temp = p[maxIdx]
        p[maxIdx] = p[0]
        p[0] = temp
        bw.write(p.joinToString(" ")+"\n")
    }
    bw.flush()
    bw.close()
}