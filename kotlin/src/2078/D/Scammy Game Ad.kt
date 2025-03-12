fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val c1 = CharArray(n) //c = operation
        val a1 = LongArray(n)// a = number
        val c2 = CharArray(n)
        val a2 = LongArray(n)
        val h = mutableListOf<Pair<Int, Int>>() //왼쪽 아니면 오른쪽 선택, 인덱스 (1 이면 왼쪽 2면 오른쪽)

        var l = 1L
        var r = 1L

        for (i in 0 until n) {
            val temp = br.readLine().split(" ")
            c1[i] = temp[0][0]
            a1[i] = temp[1].toLong()
            c2[i] = temp[2][0]
            a2[i] = temp[3].toLong()

            when { //remain은 큰 곱셈쪽으로 모든 수를 보냄
                //왜 두 수가 같을 때는 추가를 안하는 것인가??
                c1[i] == 'x' && c2[i] == 'x' -> {
                    if (a1[i] > a2[i]) h.add(1 to i)
                    else if (a1[i] < a2[i]) h.add(2 to i)
                }
                c1[i] == 'x' -> h.add(1 to i)
                c2[i] == 'x' -> h.add(2 to i)
            }
        }

        bw.write("${findAns(n, c1, a1, c2, a2, h, l, r)}\n")
    }
    bw.flush()
    bw.close()
}

fun findAns(
    n: Int,
    c1: CharArray,
    a1: LongArray,
    c2: CharArray,
    a2: LongArray,
    h: List<Pair<Int, Int>>,
    lStart: Long,
    rStart: Long
): Long {
    var l = lStart
    var r = rStart
    var cnt = 0

    for (i in 0 until n) {
        val sum = (if (c1[i] == '+') a1[i] else (a1[i] - 1) * l) + (if (c2[i] == '+') a2[i] else (a2[i] - 1) * r)
        //sum이 결국 remain sum 임
        if (cnt < h.size) {
            if (h[cnt].second == i) cnt++ //다음 것에 remain 몰아서 주는 작업, h의 second 인덱스는 띄엄 띄엄 있음
            if (cnt < h.size) {
                if (h[cnt].first == 1) l += sum //1이니까 왼쪽에 remain 추가
                else r += sum
            } else {
                l += sum //뭐로 저장하든 상관 X 둘다 같은 경우니 결국 L+R 함 default 한쪽값은 1
            }
        } else {
            r += sum //여기도 뭐로 저장하든 상관 X
        }
    }
    return l + r
}
