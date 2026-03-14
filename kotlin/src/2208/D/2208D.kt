fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    무방향 트리 n 정점
랜덤 방향 부여 하기로함
그니까 방향이 다 부여된 후 u 에서 v로 갈 수 있는지에 대한 정보가 주어짐
되는지 안되는지

i 행에 j 로 갈 수 있는지 되면 1 아니면 0

그래프를 직접 구현하는 문제가 아닌거 같음
그니까 한 정점이 어떤 정점에 최종적으로 도달한다 하면 -> 어떤 정점을 거칠지 모른다는거잖아 -> 그니까 기존 간선에 랜덤으로 더 추가한다는 얘기 같음
가짜 간선들을 지우는문제네 -> 그리고 자기자신가는 간선없으면 무조건 안됨 대각선들은 다 1이여야함  In particular, a node can always reach itself.

     */
    repeat(t) {
        val n = br.readLine().toInt()
        val directable = Array(n + 1) { BooleanArray(n + 1) { false } }
        var flag = false
        for (i in 1..n) {
            val line = br.readLine()
            for (j in 0 until n) {
                if (line[i - 1] != '1') {
                    flag = true
                }
                if (line[j] == '1') directable[i][j + 1] = true
            }
            /*
            1. 유일하게 하나만 딱 잇는 간선이 있음 정점 사이에 -> 자기 자신하고 그쪽으로 가는 간선
            2. 그거는 확정해놓고 더 있으면 그건 무조건 가짜임
            3. 다 짤라서 간선이 정점 개수-1 만큼 있어야함 n-1개
            -> 근데 이걸 어떻게 판별??
            1. 양방향이면 컷
            2. 도착지점에 결국에 어떤 시작지점이 연결되어있다 -> 그니까 중간지점을 찾는다
            -> 중간 지점 조건? -> 그 시작지점이랑 다른 간선 타고타고 같은 도착지점
            3. 정점끼리 다 있어야하고 -> visited 검증
            -> 양방향인것도 확인해야하고
            n^3 걸릴거 같은데? 3중 for문
            아니 그럼 그래프 구현? 메모리 터질거같은데 아
             */
        }
        if (flag) {
            bw.write("NO\n")
            return@repeat
        }
        val real = mutableListOf<Pair<Int, Int>>()
        for (i in 1..n) {
            for (j in 1..n) {
                if (i == j) continue
                if (directable[i][j]) {//1이면
                    var fake = false//2번 찾기
                    for (p in 1..n) {//i에서 j 로 가는게 파이널 그니까 p가 중간지점인지? i->p->j? 이거 중간지점
                        if (p != i && p != j && directable[i][p] && directable[p][j]) {
                            fake = true
                            break
                        }
                    }
                    if (!fake) {
                        real.add(i to j)
                    }
                }
            }
        }
        if(real.size!=n-1) {
            bw.write("NO\n")
            return@repeat
        }
        /*
        아 뭘 빼먹은거지 아
        다 연결되어있는지? 결국 정점에서? 최종 dfs에서 다 연결되어있는지 봐야하나? 그럴려면 일단 root를 찾아야하는게 맞을거 같은데
         */
        else {
            //1. 도착 지점에 없는지, 2. 양방향이 아닌지
            val graph = Array(n+1) {mutableListOf<Int>()}
            for(i in real.indices) {
                graph[real[i].first].add(real[i].second)
            }
            var temp = false
            for(i in 1.. n) {
                val visited = BooleanArray(n+1)
                fun dfs(n:Int) {
                    visited[n] = true
                    for(nei in graph[n]) {
                        if(!visited[nei]) {
                            dfs(nei)
                        }
                    }
                }
                dfs(i)
                for(j in 1..n) {
                    if(visited[j]!=directable[i][j]) {
                        temp = true
                        break
                    }
                }
                if(temp)break
            }
            //다 연결되어있는지 찾기
            var connected = true
            val visited = BooleanArray(n+1) {false}
            fun dfs(n:Int) {
                visited[n] = true
                for(nei in real) {
                    if(nei.first == n && !visited[nei.second]) {
                        dfs(nei.second)
                    }
                    if(nei.second == n && !visited[nei.first]) {
                        dfs(nei.first)
                    }
                }
            }
            dfs(1)

            for(i in 1.. n) {
                if(!visited[i]) {
                    connected=false
                    break
                }
            }
            if(!temp&&connected) {
                bw.write("YES\n")
                for(i in real.indices) {
                    bw.write("${real[i].first} ${real[i].second}\n")
                }
            } else {
                bw.write("NO\n")
            }
        }
    }
    bw.flush()
}