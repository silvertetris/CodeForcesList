fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    n 양수, s n사이즈 스트링, 포지션 고르고,
바로 좌우가 1인것 들중에 가운데에 있는거 하나 선택
그 하나 선택한걸 0 아니면 1
이 연산을 해서 1의 개수의 최소 와. 최대

1이 3연속이면 바꾸기 0으로 바꾸기 가능
101 이면 1로 바꾸기 가능
그리디
     */
    repeat(t) {
        val n = br.readLine().toInt()
        val line = br.readLine()
        val s = StringBuilder(line)
        val one = s.count { it == '1' }
        var mincnt = one
        var maxcnt = one
        for(i in 1 until n-1) {
            val cur = s[i]
            if(cur=='0' && s[i-1]=='1' && s[i+1]=='1') {
                maxcnt++
                s[i] = '1'
            }
        }
        mincnt = maxcnt
        for(i in 1 until n-1) {
            val cur = s[i]
            if(cur=='1' && s[i-1]=='1' && s[i+1]=='1') {
                mincnt--
                s[i] = '0'
            }
        }
        bw.write("$mincnt $maxcnt\n")
    }
    bw.flush()
    bw.close()
}