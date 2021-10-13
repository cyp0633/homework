package ObjectProgramming.one.reverse;

//反转字符串
import java.util.*;

public class ReverseString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String temp = sc.nextLine();
        for (int i = temp.length() - 1; i >= 0; i--) {
            System.out.printf("%c", temp.charAt(i));
        }
        sc.close();
    }
}
