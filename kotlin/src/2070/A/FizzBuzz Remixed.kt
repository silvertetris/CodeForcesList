fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val q = (n/15)*3
        val r =  n%15
        var result = q
        if(r>2) {
            result+=3
        }
        else {
            result+=r+1
        }
        bw.write("$result\n")
    }
    bw.flush()
    bw.close()
}