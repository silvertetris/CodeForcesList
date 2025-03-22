fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()

    repeat(t) {
        val (n, k) = br.readLine().split(" ").map { it.toInt() }
        val s = br.readLine()
        val reversedS = s.reversed()
        val mutableSet = mutableSetOf<Char>()
        for(i in s.indices) {
            mutableSet.add(s[i])
        }

        if (k == 0) {
            if (s < reversedS) {
                bw.write("YES\n")
            } else {
                bw.write("NO\n")
            }
        } else {
            if (n == 1||mutableSet.size==1) {
                bw.write("NO\n")
            } else {
                bw.write("YES\n")
            }
        }
    }

    bw.flush()
    bw.close()
}
