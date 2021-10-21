package ObjectProgramming.two.bottle;

//水瓶换水
import java.util.*;

public class BottleRefill {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num, count;
        while (sc.hasNextInt()) {
            num = sc.nextInt();
            if (num == 0) {
                break;
            }
            count = 0;
            while (num >= 2) {
                count += num / 3;
                num = num / 3 + num % 3;
                if (num == 2) {
                    count++;
                    break;
                }
            }
            System.out.printf("%d ", count);
        }
        sc.close();
    }
}
