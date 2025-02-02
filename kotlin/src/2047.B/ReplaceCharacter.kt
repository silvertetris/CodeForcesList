fun main() {
    val t = readln().toInt()
    var result = StringBuilder()
    repeat(t) {
        val n = readln().toInt()
        var word = readln()
        var arr:MutableMap<Char, Int> = HashMap()
        for(i in 0 until n) {
            if(arr.containsKey(word[i])) {
                arr[word[i]]= arr[word[i]]!!+1
            }
            else {
                arr[word[i]]=1
            }
        }
        var temp = word.toCharArray()
        val frequentChar= arr.maxBy{it.value}.key
        for(i in 0 until n) {
            if(temp[i]!=frequentChar) {
                temp[i]=frequentChar
                break
            }
        }
        result.append("${String(temp)}\n")
    }
    print(result)
}