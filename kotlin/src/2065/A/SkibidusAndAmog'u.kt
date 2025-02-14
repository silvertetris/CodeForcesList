fun main() {
    val t = readln().toInt()
    val bw = System.out.bufferedWriter()
    repeat(t) {
        var word = readln()
        word= word.dropLast(1)
        word = word.dropLast(1)
        word+='i'
        bw.write("$word\n")
    }
    bw.flush()
    bw.close()
}