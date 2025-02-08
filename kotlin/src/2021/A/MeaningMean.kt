fun main() {
    val t = readln().toInt()
    val writer = System.out.bufferedWriter()
    for (i in 0 until t) {
        var n = readln().toInt()
        var arr = readln().split(" ").map { it.toLong() }.toMutableList()
        while (true) {
            arr.sort()
            if (arr.size == 2) {
                writer.write("${(arr[0] + arr[1]) / 2}\n")
                break
            }
            val temp = (arr[0]+arr[1])/2
            arr.removeAt(1)
            arr.removeAt(0)
            arr.add(temp)
        }
    }
    writer.flush()
    writer.close()
}