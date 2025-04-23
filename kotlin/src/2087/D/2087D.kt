import java.util.Scanner;

fun isUpper(c: Char): Boolean {
    return c in 'A'..'Z';
}

fun main() {
    val scanner = Scanner(System.`in`);
    val n = scanner.nextInt();
    val h = scanner.next();
    println("? 1");
    System.out.flush();
    val s1 = scanner.next();
    if (s1 == h) {
        println("! 1");
        System.out.flush();
        return;
    }
    val s1_first_char = s1[0];
    val inferredStandardOrder = isUpper(s1_first_char);
    var L = 2;
    var R = n;
    var ans = -1;
    while (L <= R) {
        val M = L + (R - L) / 2;
        println("? $M");
        System.out.flush();
        val sM = scanner.next();
        if (sM == h) {
            ans = M;
            break;
        }
        val sM_first_char = sM[0];
        val h_first_char = h[0];
        val sM_is_upper = isUpper(sM_first_char);
        val h_is_upper = isUpper(h_first_char);
        var comparisonResult : Int;
        if (sM_is_upper == h_is_upper) {
            comparisonResult = sM.compareTo(h);
        } else {
            if (inferredStandardOrder) {
                if (sM_is_upper) {
                    comparisonResult = -1;
                } else {
                    comparisonResult = 1;
                }
            } else {
                if (sM_is_upper) {
                    comparisonResult = 1;
                } else {
                    comparisonResult = -1;
                }
            }
        }
        if (comparisonResult < 0) {
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
    println("! $ans");
    System.out.flush();
}