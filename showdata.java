import java.util.*;

public class showdata {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (sc.hasNextLine()) {
            str = sc.nextLine();
            System.out.println(str);
        }
        sc.close();
    }
}
