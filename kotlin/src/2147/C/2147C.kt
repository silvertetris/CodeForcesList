fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    n개의 화분 1부터 n 까지
어떤건 꽃 있고 어떤건 없음
1이면 있고 없으면 0
토끼도 있음
토끼는 0에 넣어야함
토끼를 좌로보거나 우로보게 가능
근데 토끼가 뜀
보고 있는 방향으로 뜀 근데 그 자리에 토끼가 있거나 반대쪽에서 글로 뛰려는 토끼가 있으면 안뜀
방향 정하기 절대 못뛰게
이게 가능한지 안되는지

조건이
한 토끼에 (분리된)
1. 양옆에 각각 2개이상의 1이 있으면 무조건 안됨
=> 따져봐야할건 2. 양옆에 1이 있는데 한쪽이 막혀있거나 다른 건너편쪽에 토끼가 있을때, -> 근데 이것도 일회성임

3. 그럼 방향이 반대여도 괜찮은건가? 예를 들어 -> 110101011 일 때 마지막 0이 안되는거 아님?

-> 그니까 결국 101 일때가 문제임 -> 101 일때 01 01 01 나오다가 이 01이 도합 홀수개가 나오면 짝을 못찾으니까 안됨
- 어차피 끝자리는 확인 안해도됨

     */
    repeat(t) {
        val n = br.readLine().toInt()
        val s = br.readLine()
        var flag = true

        var i = 0
        while (i + 2 < n && flag) {
            if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1') {
                var cnt = 1
                var j = i + 2
                while (j + 2 < n && s[j] == '1' && s[j + 1] == '0' && s[j + 2] == '1') {
                    cnt++
                    j += 2
                }
                val lZero = (i - 1 >= 0 && s[i - 1] == '0')
                val rZero = (j + 1 < n && s[j + 1] == '0')
                if (cnt % 2 == 1 && !lZero && !rZero) { //바깥에 상쇄 가능한게 있으면 0이든 1이든 알바아님
                    flag = false
                }
                i = j + 1
            } else {
                i++
            }
        }
        if (flag) {
            bw.write("YES\n")
        } else {
            bw.write("NO\n")
        }
    }
    bw.flush()
    bw.close()
}
