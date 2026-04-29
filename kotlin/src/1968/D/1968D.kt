import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    순열 p 하고 배열 a
길이 n 임 둘다
k 턴
특정 플레이어의 포지션이 x 면
점수가 a_x만큼 증가
그다음 가만히 있던가 x에서 p_x로 옮기던가
1based array
시작 P_b, P_s
둘이 동시에 움직임
그니까 계속 먹거나 움직여서 다음 점수 먹거나?
최대 depth 는 k 고
현재 지점을 계속 먹을지 말지는 어떻게 알지?
     */
    repeat(t) {
        val (n, k, pB, pS) = br.readLine().split(" ").map { it.toInt() }//턴 , 각 시작 지점
        val str1  = StringTokenizer(br.readLine())
        val str2 = StringTokenizer(br.readLine())
        val p = IntArray(n)//자리옮길곳
        val a = IntArray(n)//점수
        for(i in 0 until n) {
            p[i] = str1.nextToken().toInt()
        }
        for(i in 0 until n) {
            a[i] = str2.nextToken().toInt()
        }

        val visited = BooleanArray(n) {false}

        fun dfs(x:Int, depth:Int, remain:Long):Long {
            var result = remain
            var temp = 0L
            visited[x-1] = true
            if(!visited[p[x-1]-1] && depth<k) {
                temp = dfs(p[x-1], depth+1, result+a[x-1])
            }
            result += (k-depth) * a[x-1].toLong()
            return maxOf(result, temp)
        }
        val bodya = dfs(pB, 0, 0)
        visited.fill(false)
        val sasha = dfs(pS, 0, 0)
        if(bodya>sasha) {
            bw.write("Bodya\n")
        }
        else if(bodya<sasha) {
            bw.write("Sasha\n")
        }
        else {
            bw.write("Draw\n")
        }
    }
    bw.flush()
}