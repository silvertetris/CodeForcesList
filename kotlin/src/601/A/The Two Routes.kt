import java.util.*

fun bfs(graph: List<MutableList<Int>>, n: Int): Int {
    val dist = IntArray(n + 1) { -1 }
    val queue: Queue<Int> = LinkedList()

    dist[1] = 0
    queue.add(1)

    while (queue.isNotEmpty()) {
        val node = queue.poll()

        for (neighbor in graph[node]) {
            if (dist[neighbor] == -1) { // Not visited
                dist[neighbor] = dist[node] + 1
                queue.add(neighbor)
            }
        }
    }
    return dist[n]
}

fun main() {
    val (n, m) = readln().split(" ").map { it.toInt() }

    val railwayGraph = List(n + 1) { mutableListOf<Int>() }
    val roadGraph = List(n + 1) { mutableListOf<Int>() }
    val railwaySet = HashSet<Pair<Int, Int>>()

    repeat(m) {
        val (u, v) = readln().split(" ").map { it.toInt() }
        railwayGraph[u].add(v)
        railwayGraph[v].add(u)//undirected graph
        railwaySet.add(Pair(minOf(u, v), maxOf(u, v))) //can't be both railway and road -> save as HashSet
    }
    // each railway can be a road or a railway

    // Construct road graph (complement of railway graph)
    for (i in 1..n) { //n^2 time complexity
        for (j in i + 1..n) {
            if (Pair(i, j) !in railwaySet) { //When the rail is blue, bfs red road
                roadGraph[i].add(j)
                roadGraph[j].add(i)
            }
        }
    }
    //중간에 무조건 하나의 비어있는 vertex가 있어야함
    //traverse each vertices
    val railwayTime = bfs(railwayGraph, n)
    val roadTime = bfs(roadGraph, n)


    if (railwayTime == -1 || roadTime == -1) {
        println(-1)
    } else {
        println(maxOf(railwayTime, roadTime)) // Max time of both paths
    }
}
