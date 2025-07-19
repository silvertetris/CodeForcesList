fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        /*
        0을 옮기는 동시에 1이 필요한데 치워야하는 0 스택까지 관여함
        그러면 고려해야할건 그 2 요소고
        결국에 1옮기는건 1행동력을 소모함
         */
        var upZero = 0L
        var remainZero = 0L
        var needZero = 0L
        var needOne = 0L
        repeat(n) {
            val(a, b, c, d) = br.readLine().split(" ").map{it.toInt()}
            if(a>c) {
                remainZero+= a-c
            } else if(a<c) {
                needZero += c-a
            }
            if(b>d) { //1을 빼야함 -> 위에 남아있는 0 기록
                upZero += a
            }
            else if (b<d) { //1이 더 필요함
                needOne += d-b
            }
        }
        var temp1 = remainZero - needZero // -> 남은 0에 다가 필요한 0 뻄 그리고 양수며 음수 경우가 나뉨
        //만약 양수면 0이 남고 음수면 0이 더 필요한거임 무조건 0인데 이럼
        var answer = needOne + needZero + upZero - remainZero
        bw.write("${answer}\n")

    }
    bw.flush()
    bw.close()
}