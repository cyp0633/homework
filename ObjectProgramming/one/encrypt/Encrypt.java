package ObjectProgramming.one.encrypt;

//情报加密
import java.util.*;

public class Encrypt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        char temp;
        int n = Integer.parseInt(sc.nextLine());
        while (n-- > 0) {
            str = sc.nextLine();
            for (int i = 0; i < str.length(); i++) {
                temp = str.charAt(i);
                if ((temp >= 'a' && temp <= 'y') || (temp >= 'A' && temp <= 'Y')) {
                    temp += 1;
                } else if (temp == 'z') {
                    temp = 'a';
                } else if (temp == 'Z') {
                    temp = 'A';
                }
                System.out.printf("%c", temp);
            }
            System.out.printf("\n");
        }
        sc.close();
    }
}
