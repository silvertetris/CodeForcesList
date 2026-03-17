fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    R_u -> u로부터 도착 할 수 있는 노드 집합 (자기 자신 뺴고)
S_u-> u를 통해서 도착할 수 있는 노드의 수 (cnt)
R_v, S_v는 s_u중에 가장 큰 것을 말함

1. 가장 큰 s_v를 추가한다.
2. 모든 R_u집합에서 R_v에 있는 것들을 지움 -> 중복을 지움
-> 이렇게 하는 이유를 모름
3. u가 다 정해질 때까지 반복
     */
    repeat(t) {
        val n = br.readLine().toInt()
        val arr = Array(n+1) {BooleanArray(n+1) {false} }
        val cnt = IntArray(n) {0}

        for(i in 0 until n) {
            val line = br.readLine()
            for(j in 0 until n) {
                if(line[j+1] =='1') {
                    arr[i+1][j+1] = true
                    cnt[j+1]++
                }
            }
        }


    }
}