package ObjectProgramming.two.password;

//密码检查
import java.util.*;

public class PasswordCheck {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String pswd, strToFind;
        int isCapital, isLowercase, isSymbol, isNumber, foundPos;
        char lastChar;
        int i, sum;
        while (sc.hasNextLine()) {
            pswd = sc.nextLine();
            isCapital = isLowercase = isSymbol = isNumber = 0;
            lastChar = 0;
            sum = 0;
            if (pswd.length() < 8) {
                System.out.printf("NG\n");
                continue;
            }
            for (i = 0; i < pswd.length(); i++) {
                strToFind = new String(String.valueOf(lastChar) + pswd.charAt(i));
                foundPos = pswd.lastIndexOf(strToFind);
                if (foundPos != i - 1 && foundPos != i) {
                    System.out.printf("NG\n");
                    break;
                }
                lastChar = pswd.charAt(i);
                if (lastChar >= 'A' && lastChar <= 'Z') {
                    isCapital = 1;
                } else if (lastChar >= 'a' && lastChar <= 'z') {
                    isLowercase = 1;
                } else if (lastChar >= '0' && lastChar <= '9') {
                    isNumber = 1;
                } else
                    isSymbol = 1;
            }
            if (i == pswd.length()) {
                sum = isSymbol + isNumber + isCapital + isLowercase;
                if (sum >= 3) {
                    System.out.printf("OK\n");
                } else {
                    System.out.printf("NG\n");
                }
            }
        }
        sc.close();
    }
}
