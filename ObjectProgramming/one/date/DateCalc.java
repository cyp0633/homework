package ObjectProgramming.one.date;

//计算日期
import java.util.*;

public class DateCalc {
    static int year, totDay, month, day;
    static final int[] leapNum = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
    static final int[] normalNum = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            year = sc.nextInt();
            day = sc.nextInt();
            if (isLeap()) {
                for (int i = 1; i <= 12; i++) {
                    if (day <= leapNum[i]) {
                        month = i;
                        break;
                    }
                }
                day = day - leapNum[month - 1];
            } else {
                for (int i = 1; i <= 12; i++) {
                    if (day <= normalNum[i]) {
                        month = i;
                        break;
                    }
                }
                day = day - normalNum[month - 1];
            }
            System.out.printf("%04d-%02d-%02d\n", year, month, day);
        }
        sc.close();
    }

    static Boolean isLeap() {
        if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) {
            return true;
        }
        return false;
    }
}
