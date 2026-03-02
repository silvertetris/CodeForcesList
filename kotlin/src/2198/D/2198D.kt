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
        if (temp == 9) {
            bw.write("YES\n")
        } else if (temp == 1 && ((two >= 5)|| (three>=1 && two>=2))) {
            bw.write("YES\n")
        } else if (temp == 2 && two > 0) {
            bw.write("YES\n")
        } else if (temp == 3 && (two >= 6 || (three >= 1 && two >= 3) || three > 1)) {
            bw.write("YES\n")
        } else if (temp == 4 && two > 1) {
            bw.write("YES\n")
        } else if (temp == 5 && (two >= 7 || (three >= 1 && two >= 4) || (three >= 2 && two >= 1))) {
            bw.write("YES\n")
        } else if (temp == 6 && (two >= 3 || three > 0)) {
            bw.write("YES\n")
        } else if (temp == 7 && ((two >= 8) || (three >= 1 && two >= 5) || (three >= 2 && two >= 2))) {
            bw.write("YES\n")
        } else if (temp == 8 && ((two >= 4) || (two >= 1 && three > 0))) {
            bw.write("YES\n")
        } else {
            bw.write("NO\n")
        }
    }
    bw.flush()
    bw.close()
}