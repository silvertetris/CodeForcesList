fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val line = br.readLine().split(" ")
        val n = line[0].toInt()
        var k = line[1].toLong()

        val a = br.readLine().split(" ").map{it.toLong()}.toLongArray().sortedDescending()
        /*
        그니까 이게 기준의 한 수를 잡고
        그 수까지 만드는데 필요한 비용을 계산해야함
        dp로 해볼까?
         */
    }
    bw.flush()
}