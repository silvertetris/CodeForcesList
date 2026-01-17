fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    /*
    그니까
t가 a의 앞부분과 같으면
-> 반대네 아 이럼 첫번째는 걍 의미 없네아 아닌가 뭐 함정인가??
서로 다른 첫 포지가 t= (,   s=) 면 좋음임
그리고 레귤러 로 해야함
(())이 stack에 넣었을때 0이 되어야한다는 말임

그리고 만족하는 최대 브래킷 사이즈를 출력

     */
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val s = br.readLine()
        var idx = -1
        /*
        결국 )(패턴으로 )를 치우고 (를 넣는 방식 -> 이러면 딱 맞음 이거 없으면 안됨
        (), (()) ((()))이거 다 안됨 근데 ()(())이거는 됨 ()( 랑 (()) 틀린 부분 있어서 가능
        이 조건이 이 앞에 ()( 이후에 (이 하나 있어야 조건 만족 이거 있으면 되고 안되면 안됨.
        근데 이제 (())() 이것도 확인해야함
         */
        for (i in 0 until n - 1) {
            if (s[i] == ')' && s[i + 1] == '(') {
                idx = i
                break
            }
        }

        if (idx == -1) {
            bw.write("-1\n")
            return@repeat
        }

        var flag = false
        for (i in idx + 2 until n) {
            if (s[i] == '(') {
                flag = true
                break
            }
        }

        if (!flag) {
            bw.write("-1\n")
        } else {
            bw.write("${n - 2}\n")
        }
    }
    bw.flush()
}
