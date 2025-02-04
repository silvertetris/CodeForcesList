fun main() {
    val t = readln().toInt()
    val result = StringBuilder()
    for(i in 0 until t) {
        val (n, k) = readln().split(" ").map { it.toInt() }
        val dif = n-k
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
            for(j in 1 until n step 2) {
                val tempArr = mutableListOf<Int>()
                for(p in j until dif+j) { //최대 dif
                    tempArr.add(a[p])
                }
                for(p in j until dif+j) {
                    if(tempArr[j/2+p]!=j/2+p) {
                        result.append("${j/2+p}\n")
                        break
                    }
                }
            }
        }
    }
}