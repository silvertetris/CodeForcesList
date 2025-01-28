fun main() {
    val n = readln()
    var result =""
    for(i in n.indices) {
        if(i==0 && n[i]=='9') {
            result+='9'
            continue
        }
        if(n[i]>'4') {
            result+= '9'-n[i]
        }else{
            result+=n[i]
        }
    }
    print(result)
}