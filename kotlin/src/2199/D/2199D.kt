fun main() {
    val br = System.`in`.bufferedReader()
    val bw= System.out.bufferedWriter()
    val t = br.readLine().toInt()
    /*
    홀수 크기 배열
    1. 한 홀수를 마킹
2. 마킹한것들 중앙값 구하기 -> x
3. 마킹한거 싹다 배열에서 제거
4. 구한 x를 해당 배열에 넣기

-> 이거해서 똑같이 만드는게 가능한지
     */
    repeat(t) {
        val (n, m) = br.readLine().split(" ").map { it.toInt() }
        val a = br.readLine().split(" ").map { it.toInt() }.toMutableList().sorted()
        val b = br.readLine().split(" ").map { it.toInt() }.toMutableList().sorted()

//양끝말고 중앙쪽에 하나라도 같은 값있으면 가능하지 않나?
        val aLeft = if(n==1) 0 else 1
        val aRight = if(n==1) 0 else n-2
        val bLeft = if(m==1) 0 else 1
        val bRight = if(m==1) 0 else m-2
        var flag = false

        var l = aLeft
        var r = bLeft
        while( l<=aRight && r<=bRight) {
            if(a[l] == b[r]) {
                flag = true
                break
            }
            else if(a[l]<b[r]) l++
            else {
                r++
            }
        }
        if(flag) {
            bw.write("YES\n")
        }else {
            bw.write("NO\n")
        }
    }
    bw.flush()
}