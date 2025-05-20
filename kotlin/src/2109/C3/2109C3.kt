fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        bw.write("mul 999999999\n") //딱 범위를 안넘는 수 그리고 999999999를 곱할시에 특징
        bw.flush()
        br.readLine()
        bw.write("digit\n") //무조건 81이 나옴
        bw.flush()
        br.readLine()

        if(n!=81) {
            bw.write("add ${n-81}\n")
            bw.flush()
            br.readLine()
        }

        bw.write("!\n")
        bw.flush()
        br.readLine()
    }
}