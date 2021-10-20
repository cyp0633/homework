package ObjectProgramming.two.paper;

//抽纸片
import java.util.*;

public class DrawPaper {
    public static void main(String[] args) {
        int n, requiredSum;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        requiredSum = sc.nextInt();
        int[] num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        sc.close();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (num[i] + num[j] + num[k] == requiredSum) {
                        System.out.printf("Y\n");
                        System.exit(0);
                    }
                }
            }
        }
        System.out.printf("N\n");
    }
}
