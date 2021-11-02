package ObjectProgramming.three.provider;

//供应商问题
import java.util.*;

public class Provider {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Providers[] p = new Providers[1000];
        Vector<Providers> p = new Vector<Providers>();
        Shop[] s = new Shop[1000];
        int totalDemand = 0, totalCapacity = 0;
        int a, b, c, n, m;// n是供应商数量，m是商户数量
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            p.add(new Providers(a, b, c));
            totalCapacity += b;
        }
        for (int i = 0; i < m; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            s[i] = new Shop(a, b);
            totalDemand += b;
        }
        sc.close();
        if (totalDemand > totalCapacity) {
            System.out.printf("-1");
            System.exit(0);
        }
        p.sort(new FareComparator());
        b = 0;
        for (a = 0; a < n; a++) {
            while (s[a].demand > 0) {
                if (p.elementAt(b).capacity >= s[a].demand) {
                    p.elementAt(b).capacity -= s[a].demand;
                    System.out.printf("%d %d %d\n", p.elementAt(b).num, s[a].num, s[a].demand);
                    break;
                } else {
                    s[a].demand -= p.elementAt(b).capacity;
                    System.out.printf("%d %d %d\n", p.elementAt(b).num, s[a].num, p.elementAt(b).capacity);
                    b++;
                }
            }
        }
    }
}

class Providers {
    int num, capacity, fare;

    Providers(int n, int c, int f) {
        num = n;
        capacity = c;
        fare = f;
    }
}

class Shop {
    int num, demand;

    Shop(int n, int d) {
        num = n;
        demand = d;
    }
}

class FareComparator implements Comparator<Providers> {
    public int compare(Providers a, Providers b) {
        return Integer.compare(a.fare, b.fare);
    }
}