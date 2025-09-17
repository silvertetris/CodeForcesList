fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val line = br.readLine().split(" ")
        val n = line[0].toInt()
        var k = line[1].toLong()

        val a = br.readLine().split(" ").map{it.toLong()}.toLongArray().sortedDescending()
        //greedy 기법 ->
        //#1. 안되는 경우 -> (n * max -sum <=k) -> 이 조건이 만족되면 가능한 경우의 수임
        if(n*a.max()-a.sum() >k) {
            bw.write("-1\n")
            return@repeat
        }else { //#2. minimize the bad operation
            val min = a.min()
            //초과가능한 k 고려
            val temp = (k+a.sum())/n
            var ans = a.sumOf { temp -it } - (temp - min)
            if(min<temp) {
                ans-=a.count{it==min}-1
            }
            bw.write("$ans\n")
        }
    }
    bw.flush()
    bw.close()
}