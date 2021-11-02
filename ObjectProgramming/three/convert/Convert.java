package ObjectProgramming.three.convert;

//进制转化
import java.util.*;

public class Convert {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String hexStr = sc.next();
        sc.close();
        hexStr = hexStr.substring(2);
        int decNum = Integer.parseInt(hexStr, 16);
        System.out.printf("%d", decNum);
    }
}
