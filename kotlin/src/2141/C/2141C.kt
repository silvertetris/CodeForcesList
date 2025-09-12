fun main() {
    val n = readln().toInt()
    val sb = StringBuilder()
    var cnt = 0
    /*
    자 뭔값인지 모른다
    뭔값인지도 모르는데, 모든 각 부분배열(구간) 에 대해 최소 값을 구하라고?
    아 일단 다 넣고 앞뒤 앞뒤 앞뒤 앞뒤 앞뒤 하면 되네 아
    그냥 permutation
     */
    for (i in 0 until n) {//일단 뭐가 최소인지 모르니까 다 넣기
        sb.append("pushback a[$i]\n")
        sb.append("min\n")
        cnt += 2
    }
    for (i in 1 until n) {//각 구간 탐색
        if ((i - 1) % 2 == 0) {//짝홀 구분 -> 앞기준 permutation
            sb.append("popfront\n")
            sb.append("min\n")
            cnt+=2
            for (j in n - 2 downTo i) {
                sb.append("popback\n")
                sb.append("min\n")
                cnt+=2
            }
        } else { //뒷기준 permutation
            sb.append("popfront\n")
            sb.append("pushback a[$i]\n")
            sb.append("min\n")
            cnt+=3
            for (j in i + 1 until n) {
                sb.append("pushback a[$j]\n")
                sb.append("min\n")
                cnt+=2
            }
        }
    }
    println(cnt)
    print(sb.toString())
}
