fun main() {
    val t = readln().toInt()
    val result = StringBuilder()
    for(i in 0 until t) {
        val (n, k) = readln().split(" ").map { it.toInt() }
        val dif = n-k //한 subarray에 대한 최대 수 여기다가 +1 해야함
        val a = readln().split(" ").map { it.toInt() }.toMutableList()
        if(dif==0) {
            var tempArr = mutableListOf<Int>()
            for(j in 1 until n step 2) {
                tempArr.add(a[j])
            }
            tempArr.add(0)
            for(j in tempArr.indices) {
                if(tempArr[j]!=j+1) {
                    result.append("${j+1}\n")
                    break
                }
            }
        }
        else { //짝수니까 전체 array 에서 짝수인덱스부터 시작해야함 (1)
            var temp = 2
            for(j in 0 until dif+1) {
                if(a[j+1]!=1) {
                    temp = 1
                }
            }
            result.append("$temp\n")
        }
    }
    print(result)
}