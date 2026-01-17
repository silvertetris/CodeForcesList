fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val n = br.readLine().toInt()
        val s = br.readLine()
        /*
        그니까 0000 1111 000111 이딴거면 안되는거고
        10이 하나라도 있으면 엘리스 승? 근데 이걸 아무거나 출력해도 되나?
        결국 10이 하나라도 있으면 엘리스가 이김, -> subsequence니까 걍 1만 다 골라
        가 아니라 0000011111111 된 상태 그니까 완전 정렬된 상태에서 다른걸 골라서 정렬하고 삽입 꼽으면 되는거 아님??
         */
        var zeroCnt = s.count { it == '0' }
        val diff = mutableListOf<Int>()
        for(i in 0 until zeroCnt) {
            if(s[i]=='1') {
                diff.add(i)
            }
        }
        for(i in zeroCnt until n) {
            if(s[i]=='0') {
                diff.add(i)
            }
        }
        if(diff.size==0) {
            bw.write("Bob\n")
        } else {
            bw.write("Alice\n${diff.size}\n")
            for(i in 0 until diff.size) {
                bw.write("${diff[i] + 1} ")
            }
            bw.write("\n")
        }
    }
    bw.flush()
}