package ObjectProgramming.two.missile;

//导弹防御系统
import java.util.*;

public class MissileDefend {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int y, n, i, k, x, p, j;
        int[] a = new int[1001], l = new int[1001];
        while (sc.hasNextInt()) {
            n = sc.nextInt();
            for (i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
            }
            k = 1;
            l[1] = a[1];
            for (i = 2; i <= n; i++) {
                p = 0;
                for (j = 1; j <= k; j++) {
                    if (l[j] >= a[i]) {
                        if (p == 0 || l[j] < l[p]) {
                            p = j;
                        }
                    }
                }
                if (p == 0) {
                    l[++k] = a[i];
                } else {
                    l[p] = a[i];
                }
            }
            y = 1;
            for (i = 1; i <= n; i++) {
                x = 1;
                for (j = 1; j < i; j++) {
                    if (a[j] >= a[i] && l[j] + 1 > x) {
                        x = l[j] + 1;
                    }
                }
                l[i] = x;
                if (x > y) {
                    y = x;
                }
            }
            System.out.println(y);
        }
        sc.close();
    }
}
