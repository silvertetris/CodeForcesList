import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val str = StringTokenizer(br.readLine())
        var cT = str.nextToken().toLong()
        var cH = str.nextToken().toLong()
        var cU = str.nextToken().toLong()
        val fc =  minOf(cT, cU)
        var ans = fc*4
        cT-=fc
        cU-=fc
        if(cT>=cU) {
            val sc = minOf(cH, cT/2)
            ans+=7*sc
            cH-=sc
            cT-=2*sc
            if(cH>0) {
                if(cT==2L) {
                    ans+=7
                    cH--
                    cT-=2
                }
                if(cT==1L) {
                    ans+=5
                    cH--
                    cT--
                }
                //ans+=4*(cT/2)+1
                ans+=3*cH
            }
            else {
                if(cT>=2) {
                    ans+=4*(cT/2)+1
                    if(cT%2==1L) {
                        ans+=2
                    }
                }else {
                    ans+=3*cT
                }
            }
        }else {
            ans+=3*cU
            ans+=3*cH
        }
        bw.write("$ans\n")
    }
    bw.flush()
    /*
    1
    7 2 0
    4 2 -> 14
    3 ->

    1. U랑 T랑 먼저 매칭하고
    2. T랑 H매칭하고
    3. T 랑 T 매칭하고
    4. 나머지는 걍 3곱함
     */
}