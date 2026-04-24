import java.util.StringTokenizer

fun main() {
    val br= System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    k=0이면 바로 반환
    m+k길이가 될때까지 진행
    배열은 m길이고 초반에
    아무거나 idx를 선택하고 그 바로 뒤에 x_i+1값을 집어넣음 -> 가장 짧은 초기 배열 사이즈
    9/ 8 9
    min값 정함
    min보다 작으면 ++
    9/ 1 2 3 4 4 2
    1. 연속되면 가다가 2이상큰게 나오면 자름
    2. 연속되게 가다가 min보다 같거나 작게나오면  자름
    3. 연속되게 가다가 마지막 수보다 작거나 같은게 나온다
    -> min이랑 마지막 수 사이에 있는지 봄 min<x<=prev
    이게 만족하면 이어감
    4. 큰수는 무조건 마지막 수랑만 비교
     */
    repeat(t) {
        val n = br.readLine().toInt()
        val str = StringTokenizer(br.readLine())
        val a = IntArray(n)
        for(i in 0 until n) {
            a[i] = str.nextToken().toInt()
        }
        var cnt = 1
        var min = a[0]
        for(i in 1 until n) {
            val prev = a[i-1]
            val cur = a[i]
            if(prev>cur) {//이전 수가 더 크면
                if(min<cur) {
                    continue
                } else {
                    cnt++
                    min = cur
                }
            }
            else if(prev==cur) {
                if(cur==min) {
                    cnt++
                }
            } else if(prev+1<cur) {
                cnt++
                min=cur
            } else {
                continue
            }
        }
        bw.write("$cnt\n")
    }
    bw.flush()
}