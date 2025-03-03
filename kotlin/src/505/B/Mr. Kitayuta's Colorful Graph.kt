fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    val visited = Array(n+1) {false}
    val graph = Array(n + 20) { Array(m + 20) { mutableListOf<Int>() } }
    for (i in 0 until m) { //graph initialize
        val map = br.readLine().split(" ").map { it.toInt() }
        graph[map[0]][map[2]].add(map[1])//각 그래프에 대해 연결된 목적지를 값으로 저장, 색마다 다르니까 색은 따로 분류
        graph[map[1]][map[2]].add(map[0])
    }

    fun dfs(v: Int, c: Int) { //args have to be two : vertex and color
        visited[v] = true
        for (i in graph[v][c].indices) {
            if (!visited[graph[v][c][i]]) {
                dfs(graph[v][c][i], c)
            }
        }
    }

    val q = br.readLine().toInt()
    repeat(q) {
        val(u, v) = br.readLine().split(" ").map { it.toInt() }
        var cnt = 0
        for(i in 1..m) {
            for(j in 0..n) {
                visited[j] = false
            }
            dfs(u, i)
            if(visited[v]) cnt++
        }
        bw.write("$cnt\n")
    }
    bw.flush()
    bw.close()
}