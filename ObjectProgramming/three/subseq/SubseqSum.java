package ObjectProgramming.three.subseq;

//求子数组最大和
import java.util.*;

public class SubseqSum {
    public static void main(String[] args) {
        int[] num = new int[20000];
        int maxSum = 0, currSum = 0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            if (num[i] < 0) {
                continue;
            }
            for (int j = i; j < n; j++) {
                if (num[j] < 0) {
                    continue;
                }
                currSum = 0;
                for (int k = i; k <= j; k++) {
                    currSum += num[k];
                }
                maxSum = currSum > maxSum ? currSum : maxSum;
            }
        }
        sc.close();
        System.out.printf("%d", maxSum);
    }
}