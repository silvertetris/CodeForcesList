fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        var(n, x, k) = br.readLine().split(" ").map{it.toLong()} // x = 초기 위치 , k= 초
        val s = br.readLine()
        var temp = 0
        for(i in s.indices) {
            if(x==0L) {
                break
            }else if(s[i]=='L'){
                x--
                k--
            }
            else {
                x++
                k--
            }
        }
        if(x!=0L) {
            bw.write("0\n")
            return@repeat
        }
        var idx = 0
        var cnt = 0
        do {
            if(s[idx]=='L') {
                cnt--
                temp++
            }
            else{
                cnt++
                temp++
            }
            idx++
        }while(cnt!=0&&idx!=n.toInt())
        if(cnt!=0) {
            bw.write("1\n")
            return@repeat
        }
        bw.write("${k/temp+1}\n")
    }
    bw.flush()
    bw.close()
}