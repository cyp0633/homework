package ObjectProgramming.three.jump;

//跳跃最大长度
import java.util.*;

public class Jump {
    static int n;
    static int[] num = new int[10000];
    static boolean[] arrived = new boolean[10000];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        sc.close();
        dfs(0);
        System.out.printf("false");
    }

    static void dfs(int currPos) {
        if (arrived[currPos]) {
            return;
        }
        arrived[currPos] = true;
        if (n - 1 - currPos <= num[n]) {
            System.out.printf("true");
            System.exit(0);
        }
        for (int i = 1; i <= num[currPos]; i++) {
            dfs(currPos + i);
        }
    }
}
