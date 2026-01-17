fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()
        val a = br.readLine().split(" ").map { it.toInt() }.toIntArray().sorted()
        if(a[0]!=0) {
            bw.write("NO\n")
            return@repeat
        } else {
            var zero = 0
            var one = 0
            for(i in 0 until n) {
                if(a[i]==0) zero++
                if(a[i]==1) one++

                //1이 하나라도 있으면? 11000000으로 배치? 가능 근데 이거 이미 0위에서체크함, 1도 이미 위에 체크 그럼 걍 엘스
            }
            if(zero==1) {//0끝에
                bw.write("YES\n")
                return@repeat
            }
            if(one==0 && zero >1) {//00 231512512 해도 갈림
                bw.write("NO\n")
                return@repeat
            }
            bw.write("YES\n")
        }

    }
    bw.flush()
    bw.close()
}