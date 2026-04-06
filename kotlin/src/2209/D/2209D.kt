import java.util.StringTokenizer

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    repeat(t) {
        val str = StringTokenizer(br.readLine())
        var r = str.nextToken().toInt()
        var g = str.nextToken().toInt()
        var b = str.nextToken().toInt()
        /*
        2pair로 먼저 묶음
         */
        var rg=0
        var rb=0
        var gb=0
        while(true) {
            if((r==0&&b==0)||(b==0&&g==0) || (g==0 && r==0)) {
                break
            }
            if(r>=g&& b>=g) {
                rb++
                r--
                b--
            }
            else if(r>=b && g>=b) {
                rg++
                r--
                g--
            } else if(g>=r && b>=r) {
                gb++
                g--
                b--
            } else {
                break
            }
        }
        if(g>0) {
            bw.write("G")
            while(rg>0) {
                bw.write("RG")
                rg--
            }
            var flag = false
            while(gb>0) {
                bw.write("BG")
                gb--
                flag = true
            }
            if(flag) {
                while(rb>0) {
                    bw.write("BR")
                    rb--
                }
            } else {
                while(rb>0) {
                    bw.write("RB")
                    rb--
                }
            }
        }
        else if(b>0) {
            bw.write("B")
            while(rb>0) {
                bw.write("RB")
                rb--
            }
            var flag = false
            while(rg>0) {
                bw.write("RG")
                rg--
                flag= true
            }
            if(flag) {
                while(gb>0) {
                    bw.write("BG")
                    gb--
                }
            }else {
                while(gb>0) {
                    bw.write("GB")
                    gb--
                }
            }
        }
        else {
            if(r>0) {
                bw.write("R")
            }
            while(rg>0) {
                bw.write("GR")
                rg--
            }
            var flag = false
            while(rb>0) {
                bw.write("BR")
                rb--
                flag= true
            }
            if(flag) {
                while(gb>0) {
                    bw.write("BG")
                    gb--
                }
            }else {
                while(gb>0) {
                    bw.write("GB")
                    gb--
                }
            }
        }
        bw.write("\n")
        bw.flush()
    }
}