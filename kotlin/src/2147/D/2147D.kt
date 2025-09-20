import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    n개의 양수 배열 a
엘리스가 먼저
0보다 큰 값을 고름 a 에 최소 1개 있는것들 중
1포인트 얻음
그리고 고른 값은 x-1이 됨
아 그니까 만약 배열 안에 8이 3개면 3포얻고 모든 8은 7이 됨
모든 배열이 0이되면 겜 끝

걸리는 것:
- 제일 많은걸 greedy로 줄였다가, 그 준 수가 상대편에게 엄청나게 많은 점수를 줄 수가 있음
ex) 초기 상태 22211 이여서 처음에 2를 선택했다가 11111이 되고 상대편이 이기게됨
그래서 11을 먼저 고르고 2점 얻고 상대편 3점 주고 나도 3점 더먹어서 5:3으로 이김
엥 이러면 관계없는거 아닌가? 어차피 엘리스가 이기는거 아닌가?
밥이 이기는 경우가 있을까? 없다 신경쓰기 ㄴㄴ 무조건 엘리스가 이기는 게임임

결국 결과가 달라지는데 걸리는 변수는 각 값의 count 말고 없음
특정 값보다 작은 값들의 count를 신경쓰면 됨
-> dp 로 일일히 +1하면 시간초과남 -> 축약형 dp?
-> 일단 카운트 그리디?

1. count는 해쉬맵으로함 -> 10^9면 배열했다가 무조건 메모리초과남
2. 카운트가 많은놈을 일단 다 뽑아내야함
33311
3 3
5
2 3
3 3

     */
    repeat(t) {
        val n = br.readLine().toInt()
        val arr = br.readLine().split(" ").map { it.toInt() }

        val count = HashMap<Int, Int>()//값, 카운트
        for (i in arr) {
            count[i] = count.getOrDefault(i, 0) + 1
        }

        val pq = PriorityQueue<Pair<Int, Int>> { a, b -> //값, 카운트 -> 이건 근데 마지막만 생각하면 될거 같은데 마지막을 누가 가져가냐
            if (a.first != b.first) a.first - b.first else a.second - b.second
        }
        for ((a, b) in count) if (a > 0) pq.add(a to b)

        var a = 0L
        var b = 0L
        var flag = true

        while (pq.isNotEmpty()) {
            val (u, v) = pq.poll()
            if (count.getOrDefault(u, 0) != v || v == 0) continue
            //아 근데 2 2 2 1 1 같은 경우는 어떡하지? 밥이 이기는데 이러면 -> 결국 숫자가 바뀌는 구간을 잡아줘야함
            //우선순위에서 카운트 위주말고 값이 작은것부터 가져가면 일단 더하고 큰놈들 순서를 둘이 바꾸면 될거 같은데
            if (flag) a += v else b += v
            flag = !flag

            count[u] = 0
            if (u-1 > 0) {
                val temp = count.getOrDefault(u-1, 0) + v
                count[u-1] = temp
                pq.add(u-1 to temp)
            }
        }
        bw.write("$a $b\n")
    }
    bw.flush()
}