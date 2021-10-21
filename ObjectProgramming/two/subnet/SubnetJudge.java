package ObjectProgramming.two.subnet;

//子网判断
import java.util.*;

public class SubnetJudge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[4], b = new int[4], mask = new int[4];
        int count;
        String aStr, bStr, maskStr;
        maskStr = sc.nextLine();
        aStr = sc.nextLine();
        bStr = sc.nextLine();
        sc.close();
        count = 0;
        for (int i = 0; i < maskStr.length(); i++) {
            if (maskStr.charAt(i) == '.') {
                count++;
                continue;
            }
            mask[count] *= 10;
            mask[count] += maskStr.charAt(i) - '0';
        }
        count = 0;
        for (int i = 0; i < aStr.length(); i++) {
            if (aStr.charAt(i) == '.') {
                count++;
                continue;
            }
            a[count] *= 10;
            a[count] += aStr.charAt(i) - '0';
        }
        count = 0;
        for (int i = 0; i < bStr.length(); i++) {
            if (bStr.charAt(i) == '.') {
                count++;
                continue;
            }
            b[count] *= 10;
            b[count] += bStr.charAt(i) - '0';
        }
        for (int i = 0; i < 4; i++) {
            if ((a[i] & mask[i]) != (b[i] & mask[i])) {
                System.out.printf("0");
                System.exit(0);
            }
        }
        System.out.printf("1");
    }
}
