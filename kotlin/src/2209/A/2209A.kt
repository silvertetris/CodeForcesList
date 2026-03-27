fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        var (n, c, k) = br.readLine().split(" ").map { it.toInt() }//몬스터 수, 전투력, 코인 수
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray().sorted()
        //최대 전투력 구하기
        var combat = c.toLong()
        var flag = false
        for(i in 0 until n) {
            if(a[i]<= combat) {
                val diff = combat - a[i]//이 차이 만큼 최종 점수에 더해주고 코인수에서 빼야함
                if(flag) {
                    combat+= a[i]
                    continue
                }
                if(k-diff<=0) {
                    flag = true
                    combat+= k + a[i]
                } else {
                    combat += a[i] + diff
                    k-=diff.toInt()
                }
            }else {
                break
            }
        }
        bw.write("$combat\n")
    }
    bw.flush()
}