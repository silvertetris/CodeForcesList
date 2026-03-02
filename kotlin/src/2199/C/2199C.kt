fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    2행 많은 열 지뢰찾기 만듦
비거나 마인 있어야함
서로 인접하거나 대각선으로 인접해서 네이버링이라함

1. 각 빈거는 무조건 최대 1개의 지뢰를 네이버링
2. 지뢰 있는 거랑 네이버링한 빈 거는 k임
3. 이거 만족하는 최소 칼럼 수

안되는 경우부터 생각하자
y= k%5 ->
     */
    repeat(t) {
        val k = br.readLine().toInt()
        if(k==1) {
            bw.write("YES\n1\n*\n" +
                    ".\n")
            return@repeat
        }
        val far = k%5
        if(far==2||far==4) {
            bw.write("NO\n")
            return@repeat
        }
        var columns=0

        if(far ==0) {
            columns = 3*(k/5)//1개가 5개
        } else if(far ==1) {
            columns = 3*((k-1)/5)+1//양끝 패턴
        } else {
            columns = 3*((k-3)/5)+2
        }

        val firstLine = CharArray(columns) { '.' }
        val secondLine = CharArray(columns) { '.' }

        if(far==0) {
            for(i in 0 until (k/5)) {
                firstLine[3*i+1] = '*'
            }
        }
        else if(far ==1) {
            for(i in 0..(k-1)/5) {
                firstLine[3*i]='*'
            }
        }
        else{
            for(i in 0..(k-3)/5) {
                firstLine[3*i+1]='*'
            }
        }
        bw.write("YES\n")
        bw.write("$columns\n")
        bw.write("${firstLine.concatToString()}\n")
        bw.write("${secondLine.concatToString()}\n")
    }
    bw.flush()
}