fun main() {
    val t = readln().toInt()
    val bw = System.out.bufferedWriter()
    repeat(t) {
        val n = readln().toInt()
        var result = Array<Int>(n) {0}
        var arr: Array<CharArray> = Array(n) { CharArray(4) { ' ' } }
        for(i in 0 until n) {
            arr[i] = readln().toCharArray()
            for(j in 0 until 4) {
                if(arr[i][j]=='#') {
                    result[n-i-1] = j+1
                    break
                }
            }
        }
        bw.write("${result.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
}