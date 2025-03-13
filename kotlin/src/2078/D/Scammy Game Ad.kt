fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt() // Read the number of test cases

    repeat(t) {
        val n = br.readLine().toInt() // Read the number of pairs of gates

        // Arrays to store operations and values for left and right gates
        val op = Array(n + 1) { Array(2) { "+" } }
        val value = Array(n + 1) { IntArray(2) }

        // Read the input for each pair of gates
        for (i in 1..n) {
            val tmp = br.readLine().split(" ")
            op[i][0] = tmp[0]  // Operation for left gate
            value[i][0] = tmp[1].toInt()  // Value for left gate
            op[i][1] = tmp[2]  // Operation for right gate
            value[i][1] = tmp[3].toInt()  // Value for right gate
        }

        // Initialize the first gate as "+ 1" to match the problem's starting condition
        op[0] = arrayOf("+", "+")
        value[0] = intArrayOf(1, 1)

        // dp[i][0] = maximum people in left lane after processing i-th pair of gates
        // dp[i][1] = maximum people in right lane after processing i-th pair of gates
        val dp = Array(n + 2) { LongArray(2) }
        dp[n + 1][0] = 1 // Base case: 1 person in left lane
        dp[n + 1][1] = 1 // Base case: 1 person in right lane

        // Backward DP: calculating the max possible people from the last gate to the first
        for (i in n downTo 1) { //어차피 곱하기를 거쳐서 나오고 그중에 maxOf 를 한다면 val 끼리 비교를 안해도 됨
            // If left gate is "x a", multiply (a-1) times max possible people and add
            dp[i][0] = if (op[i][0] == "x") {
                dp[i + 1][0] + (value[i][0] - 1) * maxOf(dp[i + 1][0], dp[i + 1][1])
            } else { // If it's "+ a", just take the same max value from the next stage
                dp[i + 1][0]
            }

            // If right gate is "x a", multiply (a-1) times max possible people and add
            dp[i][1] = if (op[i][1] == "x") {
                dp[i + 1][1] + (value[i][1] - 1) * maxOf(dp[i + 1][0], dp[i + 1][1])
            } else {
                dp[i + 1][1]
            }
        }

        // Now compute the final result
        var ans = 0L
        for (i in 1..n) {
            var sm = 0
            if (op[i][0] == "+") sm += value[i][0] // Sum if left gate is "+"
            if (op[i][1] == "+") sm += value[i][1] // Sum if right gate is "+"
            ans += sm * maxOf(dp[i + 1][0], dp[i + 1][1])
        }

        // Add the final values from dp[1]
        ans += dp[1][0] + dp[1][1]
        bw.write("$ans\n") // Output the answer
    }

    bw.flush()
}
