fun main() {
    val t = readln().toInt()
    val bw = System.out.bufferedWriter()
    repeat(t) {
        var word = readln()
        var cnt = word.length
        for(i in word.length-1 downTo  1) {
            if(word[i]==word[i-1]) {
                cnt = 1
                break
            }
        }
        bw.write("$cnt\n")
    }
    bw.flush()
    bw.close()
}