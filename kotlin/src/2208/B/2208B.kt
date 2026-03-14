fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val(n, k, p, m) = br.readLine().split(" ").map { it.toInt() }//덱 크기, 플레이 포지션, 윈 컨디션 카드, 최대 코스트
        val a = br.readLine().split(" ").map { it.toInt() }
        if(k>=n) {
            bw.write("${m/a[p-1]}\n")
            return@repeat
        } else { //그니까 k 가 더 작을경우 -> 어차피 사이클을 돌림
            val pCost = a[p-1]
            var initSum = pCost
            if(p>k) {
                val temp = mutableListOf<Int>()
                for(i in 0 until p-1) {
                    temp.add(a[i])
                }
                temp.sort()
                for(i in 0 until p-k) {
                    initSum+=temp[i]
                }
            }
            if(initSum>m) {
                bw.write("0\n")
                return@repeat
            }
            /*
            사이클 돌리는걸 계산
            저기까지 한사이클 돌리고
            initSum 사이클 계속 돌릴거 아닌가 -> 가 아니지 p가 근처있는데 이건 맨뒤로 보내니까 여기서 시작이지
            어차피 된다면 p번째까지 체크 후에 최소값 k만큼 보내는거임 그 pCost 포함해서 그니까 k만큼을 한사이클에 고르는거임 시작 제외
             */
            val cycle = mutableListOf<Int>()
            var cost = pCost
            for(i in 0 until n) {
                if(i!=p-1) {
                    cycle.add(a[i])
                }
            }
            cycle.sort()
            //initSum 연산 후에 다시 불러모으기
            for(i in 0 until n-k) {
                cost +=cycle[i]
            }
            bw.write("${1+((m-initSum)/cost)}\n")
        }
    }
    bw.flush()
}