package ObjectProgramming.one.count;

//计算int型二进制1的个数
import java.util.*;

public class CountOne {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num, count = 0;
        num = sc.nextInt();
        while (num > 0) {
            count += num % 2;
            num /= 2;
        }
        System.out.printf("%d", count);
        sc.close();
    }
}
