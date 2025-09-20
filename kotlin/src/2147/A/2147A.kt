fun main() {
    val br= System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (x, y) = br.readLine().split(" ").map { it.toInt() }
        if(y>x) {
            bw.write("2\n")
        } else if(x-1<=y || y==1) {
            bw.write("-1\n")
        } else {
            bw.write("3\n")
        }
    }
    bw.flush()
    bw.close()
}