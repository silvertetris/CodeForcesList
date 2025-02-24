fun main() {
    val n = readln().toInt()
    val s = readln().toCharArray()
    var result = StringBuilder()
    for(i in 0 until n) {
        if(result.length%2==0 || result[result.lastIndex]!=s[i]) {
            result.append(s[i])
        }
    }
    if(result.length%2!=0) {
        result.deleteAt(result.lastIndex)
    }
    println(n-result.length)
    print(result)
}