fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine()
        //숫자 중에서 하나만 제곱한 결과를 바꿔치기함 그니까 1 2 3 만 제곱 가능
        //숫자 합이 9의 배수면 9제곱
        var sum = 0
        var two = 0
        var three = 0
        for (i in n.indices) {
            if (n[i] == '2') two++
            else if (n[i] == '3') three++

            sum += n[i] - '0'
        }
        val temp = 9 - (sum % 9)//필요한 수
        /*
        2면
        2, 4, 6, 8, 1, 3, 5, 7
        6면
        6, 3, 6, 3, 6
        섞을 때
        1-> 2가 5개 아니면 6이 1개 2가 2개
        2-> 2가 1개
        3-> 2가 6개 아니면 6이 2개 아니면 2가 3개, 6이 1개
        4-> 2가 2개
        5-> 2가 7개 아니면 6이 1개고 2가 4개 아니면 6이 2개고 2가 1개
        6-> 6이 1개 아니면 2가 3개
        7-> 2가 8개 아니면 6이 1개고 2가5개 아니면 6이 2개고 2가 2개
        8-> 2가 4개 아니면 6이 1개고 2가 1개

         */
        if(temp==9) {
            bw.write("YES\n")
            return@repeat
        }
        var ok = false

        for (a in 0..minOf(two, 8)) {
            for (b in 0..minOf(three, 2)) {
                if ((2*a + 6*b) % 9 == temp) {
                    ok = true
                    break
                }
            }
            if (ok) break
        }

        bw.write(if (ok) "YES\n" else "NO\n")
    }
    bw.flush()
    bw.close()
}