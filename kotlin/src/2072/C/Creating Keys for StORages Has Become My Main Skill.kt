import kotlin.math.pow

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()
    repeat(t) {
        val (n, x) = br.readLine().split(" ").map { it.toLong() }
        val arr = LongArray(n.toInt()) { 0L }
        if (n == 1L) {
            bw.write("$x\n")
        } else if (n > x + 1) {
            for (i in 0..x) {
                arr[i.toInt()] = i
            }
            bw.write("${arr.joinToString(" ")}\n")
        } else {
            val temp = Integer.toBinaryString(x.toInt())
            var num = Integer.MAX_VALUE
            for (i in temp.length - 1 downTo 0) {
                if (temp[i] == '0') {
                    num = temp.length - (i) - 1 // 0이 나오는 자리임
                    break
                }
            }
            if (num == Integer.MAX_VALUE) {
                if (n < 2.0.pow(temp.length - 1).toLong()+1) {
                    for (i in 0 until n - 1) {
                        arr[i.toInt()] = i
                    }
                    arr[(n - 1).toInt()] = x
                } else {
                    if(n>=x+1) {
                        for(i in 0 .. x) {
                            arr[i.toInt()] = i
                        }
                    }else {
                        for(i in 0 until n) {
                            arr[i.toInt()] = i
                        }
                    }
                }
            } else {
                if (n < 2.0.pow(num).toLong()) {
                    for (i in 0 until n - 1) {
                        arr[i.toInt()] = i
                    }
                    arr[(n - 1).toInt()] = x
                } else {
                    for (i in 0 until 2.0.pow(num).toLong()) {
                        arr[i.toInt()] = i
                    }
                    if(arr[(n-1).toInt()]==0L) {
                        arr[(n-1).toInt()] = x
                    }
                }
            }
            bw.write("${arr.joinToString(" ")}\n")
        }
    }
    bw.flush()
    bw.close()
}