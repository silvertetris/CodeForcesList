import java.util.*

fun main() {

    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val pow = IntArray(100001)
    val MOD = 998_244_353
    pow[0] = 1
    for (i in 1..100000) {
        pow[i] = (pow[i - 1] * 2) % MOD
    }

    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val p = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        val q = br.readLine().split(" ").map { it.toInt() }.toIntArray()

        val indexP = IntArray(n) //인덱스를 배열에 담음
        for (index in p.indices) {
            val temp = p[index]
            indexP[temp] = index
        }
        val indexQ = IntArray(n)
        for (index in q.indices) {
            val temp = q[index]
            indexQ[temp] = index
        }

        //시간초과-> 모든 경우의 수에 대해 다 확인하니까 남 -> 우선순위 큐로 최대 값 유지 -> p, q 유지 시키면서 서로 비교하면서 최대값 찾기
        val queueP = PriorityQueue<Int>(compareByDescending { it })
        val queueQ = PriorityQueue<Int>(compareByDescending { it })
        val r = IntArray(n)

        for (i in 0 until n) {
            queueP.add(p[i])
            queueQ.add(q[i])

            //P에서 큰놈 나오면
            val maxP = queueP.peek()
            val curPidx = indexP[maxP]
            val oppositeIdxQ = i - curPidx
            val oppositeQval = q[oppositeIdxQ]
            val a1 = maxOf(maxP, oppositeQval)
            val b1 = minOf(maxP, oppositeQval)

            //Q
            val maxQ = queueQ.peek()
            val curQidx = indexQ[maxQ]
            val oppositeIdxP = i - curQidx
            val oppositePval = p[oppositeIdxP]
            val a2 = maxOf(maxQ, oppositePval)
            val b2 = minOf(maxQ, oppositePval)

            
            //둘중에 뭐가 큰지 맨 마지막에 비교
            val idx = if (a1 > a2) {
                a1 to b1
            } else if (a1 < a2) {
                a2 to b2
            } else {
                if (b1 >= b2) a1 to b1 else a2 to b2
            }
            
            //결과
            val currentResult = (pow[idx.first] + pow[idx.second]) % MOD
            r[i]= currentResult
        }
        bw.write("${r.joinToString(" ")}\n")
    }
    bw.flush()
    bw.close()
}
