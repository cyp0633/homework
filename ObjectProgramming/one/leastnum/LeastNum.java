package ObjectProgramming.one.leastnum;

import java.util.*;

//输出较小数
public class LeastNum {
    public static void main(String[] args) {
        int n, k, temp;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        int[] num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (num[i] > num[j]) {
                    temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            System.out.printf("%d ", num[i]);
        }
        sc.close();
    }
}