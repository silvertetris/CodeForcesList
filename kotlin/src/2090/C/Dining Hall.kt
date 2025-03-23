import java.util.*

data class TableEntry(val priority: Int, val tx: Int, val ty: Int)

fun main() {
    val q = readLine()!!.toInt()
    repeat(q) {
        val n = readLine()!!.toInt()
        val tList = readLine()!!.split(" ").map { it.toInt() }

        val countMap = mutableMapOf<Pair<Int, Int>, Int>()
        val pq = PriorityQueue<Triple<Int, Int, Int>>(compareBy({ it.first }, { it.second }, { it.third }))
        var s = 0
        var tx = 0

        for (t in tList) {
            if (t == 0) {
                while (true) {
                    val ty = s - tx
                    val key = Pair(tx, ty)
                    val count = countMap.getOrDefault(key, 0)
                    if (count == 0) {
                        countMap[key] = 1
                        val priority = 3 * (tx + ty) + 3
                        pq.add(Triple(priority, tx, ty))
                        val cellX = 3 * tx + 1
                        val cellY = 3 * ty + 1
                        println("$cellX $cellY")
                        tx += 1
                        if (tx > s) {
                            s += 1
                            tx = 0
                        }
                        break
                    } else {
                        tx += 1
                        if (tx > s) {
                            s += 1
                            tx = 0
                        }
                    }
                }
            } else {
                while (true) {
                    if (pq.isEmpty()) {
                        break
                    }
                    val (currentPriority, currentTx, currentTy) = pq.poll()
                    val key = Pair(currentTx, currentTy)
                    val currentCount = countMap.getOrDefault(key, 0)
                    if (currentCount >= 4) {
                        continue
                    }
                    val expectedPriority = when (currentCount) {
                        0 -> 3 * (currentTx + currentTy) + 2
                        1 -> 3 * (currentTx + currentTy) + 3
                        2 -> 3 * (currentTx + currentTy) + 3
                        3 -> 3 * (currentTx + currentTy) + 4
                        else -> error("Invalid count")
                    }
                    if (currentPriority != expectedPriority) {
                        continue
                    }
                    val seatIndex = currentCount
                    countMap[key] = currentCount + 1
                    val (cellX, cellY) = when (seatIndex) {
                        0 -> Pair(3 * currentTx + 1, 3 * currentTy + 1)
                        1 -> Pair(3 * currentTx + 1, 3 * currentTy + 2)
                        2 -> Pair(3 * currentTx + 2, 3 * currentTy + 1)
                        3 -> Pair(3 * currentTx + 2, 3 * currentTy + 2)
                        else -> error("Invalid seat index")
                    }
                    if (currentCount + 1 < 4) {
                        val newPriority = when (currentCount + 1) {
                            1 -> 3 * (currentTx + currentTy) + 3
                            2 -> 3 * (currentTx + currentTy) + 3
                            3 -> 3 * (currentTx + currentTy) + 4
                            else -> error("Invalid new count")
                        }
                        pq.add(Triple(newPriority, currentTx, currentTy))
                    }
                    println("$cellX $cellY")
                    break
                }
            }
        }
    }
}