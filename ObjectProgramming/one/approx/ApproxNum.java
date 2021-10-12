package ObjectProgramming.one.approx;
//求近似数

import java.util.*;

public class ApproxNum {
    public static void main(String[] args) {
        double num;
        int n;
        Scanner sc=new Scanner(System.in);
        num=sc.nextDouble();
        n=(int)Math.round(num);
        System.out.printf("%d", n);
        sc.close();
    }
}
