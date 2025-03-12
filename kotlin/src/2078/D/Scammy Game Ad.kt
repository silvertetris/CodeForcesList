fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val t = br.readLine().toInt()

    repeat(t) {
        val n = br.readLine().toInt()

        val dp1 = Array(n + 1) { LongArray(2) { 0 } } // left start
        val dp2 = Array(n + 1) { LongArray(2) { 0 } } // right start
        // base cases
        dp1[0][0] = 1
        dp1[0][1] = 1
        dp2[0][0] = 1
        dp2[0][1] = 1
        var extra = 0L

        // transition
        for (i in 1..n) {
            val gate = br.readLine().split(" ")
            val leftGate = gate[0]
            val leftValue = gate[1].toInt()
            val rightGate = gate[2]
            val rightValue = gate[3].toInt()

            if (i == 1) {
                dp1[1][0] = (if (leftGate == "*") leftValue else 1 + leftValue).toLong()
                dp1[1][1] = (if (leftGate == "*") leftValue else 1 + leftValue).toLong()
                dp2[1][0] = (if (rightGate == "*") rightValue else 1 + rightValue).toLong()
                dp2[1][1] = (if (rightGate == "*") rightValue else 1 + rightValue).toLong()
                extra = dp1[1][0] + dp2[1][0] - 2
                continue
            }

            if (leftGate == "+" && rightGate == "+") {
                dp1[i][0] = dp1[i-1][0] + leftValue
                dp1[i][1] = dp1[i-1][1] + leftValue
                dp2[i][0] = dp2[i-1][0] + rightValue
                dp2[i][1] = dp2[i-1][1] + rightValue
            }

            else if (leftGate == "+" && rightGate == "x") {
                dp1[i][0] = dp1[i-1][0] + leftValue
                dp2[i][0] = dp2[i-1][0] * rightValue
            }

            else if (leftGate == "x" && rightGate == "+") {
                dp2[i][0] = dp2[i-1][0] + leftValue
                dp1[i][0] = dp1[i-1][0] * rightValue
            }

            else {
                dp1[i][0] = dp1[i-1][0] * leftValue
                dp2[i][0] = dp2[i-1][0] * rightValue
            }
            extra = dp1[i][0] + dp2[i][0]
        }

        bw.write("${dp1[n][0] + dp2[n][0]}\n")
    }

    bw.flush()
}
