fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    1. 하나 높이기
2. 둘다 높이기 -> 이건 둘다 같을때만 가능
첫 타워를 c높이에 맞게 그리고 두번쨰 타워를 d 높이에 맞게
-> 연산 최소
     */
    repeat(t) {
        val(a, b, c, d) = br.readLine().split(" ").map { it.toInt() }
        var up = c-a+d-b
        //2번 연산 쓸 수 있을때
        var two = minOf(c, d)- maxOf(a, b)
        two = maxOf(two, 0)
        up -= two
        bw.write("$up\n")
    }
    bw.flush()
}