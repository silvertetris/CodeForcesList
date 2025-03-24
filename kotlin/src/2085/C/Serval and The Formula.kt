fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val (x, y) = br.readLine().split(" ").map { it.toBigInteger() }
        if (x == y) { //if x==y
            bw.write("-1\n")
        }
        //2의 n 승에 집중-> binary search가 아님
        //결국 두 결과값이 같으려면 (x+k) && (y+k) == 0 이여야함
        //서로 간에 겹치는게 없어야함 둘을 a, b 라 쳤을 때
        //ex -> 10000, 01111 -> 둘이 합치고 xor 했을 때 그냥 더 한 값임을 알 수 있음
        //좌항은 2^l -> 엄청 큰 값
        //우항은 2^l-x+y -> 큰 값보다 작은 값 -> x>y 라 가정했을 때
        //좌항은 제일 큰 수만 1이고 나머지는 그 1보다 작은 여러개의 수가 있음
        //결국에 둘이 더하거 xor이 같을 수 밖에 없는 값임.
        else {
            bw.write("${2.toBigInteger().pow(48) - maxOf(x, y)}\n") //이게 k 값
        }
    }
    bw.flush()
    bw.close()
}