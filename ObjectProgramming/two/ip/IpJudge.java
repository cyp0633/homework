package ObjectProgramming.two.ip;

//IP地址判定
import java.util.*;

public class IpJudge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ip;
        ip = sc.nextLine();
        sc.close();
        int num = 0;
        char ch;
        for (int i = 0; i < ip.length(); i++) {
            ch = ip.charAt(i);
            if (ch == '.') {
                num = 0;
                continue;
            } else if (ch >= '0' && ch <= '9') {
                num *= 10;
                num += ch - '0';
                if (num > 255) {
                    System.out.printf("NO");
                    System.exit(0);
                }
            } else {
                System.out.printf("NO");
                System.exit(0);
            }
        }
        System.out.println("YES");
    }
}
