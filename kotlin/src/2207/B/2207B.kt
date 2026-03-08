fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    이분 탐색 예외 -> 같은 수가 나오면 탐색의 오류가 남 -> 완전탐색으로 해야함

    1. 전체 추가 -> 위험도
    2. 시간을 애니메트로닉스 수로 나눔 -> 스프레드 하는게 제일 최악
    3. 최악에서 최소 뽑기 -> 계산해서 하나씩 치움
    4. 그냥 배열에서 위험도를 하나씩 계산
     */
    fun addDanger(arr: ArrayList<Int>, add: Int) {
        if (arr.isEmpty() || add == 0) return

        var remain = add
        var i = 1

        while (i < arr.size) {
            val diff = arr[i] - arr[i - 1]
            if (diff > 0L) {
                val need = diff * i
                if (remain < need) {
                    val q = remain / i
                    val r = remain % i

                    for (j in 0 until i) arr[j] += q
                    for (j in 0 until r) arr[j] += 1

                    arr.sort()
                    return
                } else {
                    for (j in 0 until i) arr[j] = arr[i]
                    remain -= need
                }
            }
            i++
        }

        val size = arr.size
        val q = remain / size
        val r = remain % size

        for (j in 0 until size) arr[j] += q
        for (j in 0 until r) arr[j] += 1

        arr.sort()
    }

    repeat(t) {
        val (n, m, l) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt()}.toIntArray().sorted()

        val dan = IntArray(n + 1)
        dan[0] = a[0]
        for (i in 1 until n) dan[i] = a[i] - a[i - 1]
        dan[n] = l - a[n - 1]

        var worse = minOf(m, n + 1)
        val arr = ArrayList<Int>()//위험도 최대

        for (i in 0 until worse) arr.add(0)

        for (turn in 0 until n) {
            addDanger(arr, dan[turn])

            arr.removeAt(arr.size - 1)
            arr.add(0)
            arr.sort()

            val nextWorse = minOf(m, n - turn)
            while (arr.size > nextWorse) {
                arr.removeAt(0)
            }
        }

        addDanger(arr, dan[n])
        bw.write("${arr[arr.size - 1]}\n")
    }

    bw.flush()
}