fun countInversions(arr: IntArray): Int {
    val temp = arr.copyOf()
    return mergeSortAndCount(arr, temp, 0, arr.size - 1)
}

fun mergeSortAndCount(arr: IntArray, temp: IntArray, left: Int, right: Int): Int {
    var count = 0
    if (left < right) {
        val mid = (left + right) / 2
        count += mergeSortAndCount(arr, temp, left, mid)
        count += mergeSortAndCount(arr, temp, mid + 1, right)
        count += mergeAndCount(arr, temp, left, mid, right)
    }
    return count
}

fun mergeAndCount(arr: IntArray, temp: IntArray, left: Int, mid: Int, right: Int): Int {
    var i = left
    var j = mid + 1
    var k = left
    var invCount = 0

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++]
        } else {
            temp[k++] = arr[j++]
            invCount += (mid - i + 1)
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++]
    }

    while (j <= right) {
        temp[k++] = arr[j++]
    }

    for (i in left..right) {
        arr[i] = temp[i]
    }

    return invCount
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    for (testCase in 1..t) {
        val n = br.readLine().toInt()
        val arr = br.readLine().split(" ").map { it.toInt() }.toIntArray()

        var bestL = 1
        var bestR = 1
        var minInversions = Int.MAX_VALUE

        for (l in 0 until n) {
            for (r in l until n) {
                val newArr = arr.copyOf()
                val shiftedArr = newArr.sliceArray(l..r).apply {
                    val firstElement = this.first()
                    for (i in 1 until this.size) {
                        this[i - 1] = this[i]
                    }
                    this[this.size - 1] = firstElement
                }

                val finalArr = newArr.copyOfRange(0, l) + shiftedArr + newArr.copyOfRange(r + 1, n)

                val invCount = countInversions(finalArr)

                if (invCount < minInversions) {
                    minInversions = invCount
                    bestL = l + 1 // 1-indexed
                    bestR = r + 1 // 1-indexed
                }
            }
        }

        bw.write("$bestL $bestR\n")
    }
    bw.flush()
    bw.close()
    br.close()
}
