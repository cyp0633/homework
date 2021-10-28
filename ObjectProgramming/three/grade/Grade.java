package ObjectProgramming.three.grade;

//学生成绩
import java.util.*;

public class Grade {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] score = new int[30001];
        int n, m, a, b, maxGrade;
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            score[i] = sc.nextInt();
        }
        String type;
        for (int i = 0; i < m; i++) {
            type = sc.next();
            a = sc.nextInt();
            b = sc.nextInt();
            if (type.equals("Q")) {
                maxGrade = -114514;
                for (int j = a; j <= b; j++) {
                    if (score[j] > maxGrade) {
                        maxGrade = score[j];
                    }
                }
                System.out.printf("%d ", maxGrade);
            } else {
                score[a] = b;
            }
        }
        sc.close();
    }
}
