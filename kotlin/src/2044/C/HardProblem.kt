fun main() {
    val t = readln().toInt()
    val result = Array<Int>(t){0}
    for(i in 0 until t) {
        var(m, a, b, c) = readln().split(" ").map { it.toInt() }
        var temp =0
        var total = 2*m
        if(m>=a) {
            temp+=a
            total-=a
        }
        else if(m<a) {
            temp+=m
            total-=m
        }
        if(m>=b) {
            temp+=b
            total-=b
        }
        else if(m<b) {
            temp+=m
            total-=m
        }
        if(total>=c) {
            temp+=c
        }
        else if(total<c) {
            temp+=total
        }
        result[i]=temp
    }
    for(i in 0 until t) {
        println(result[i])
    }
}