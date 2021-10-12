package ObjectProgramming.one.friend;

//找朋友
import java.util.*;

public class FindFriend {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        sc.nextInt();
        int[] favouriteBookCount = new int[100000], favBook = new int[100000];
        // HashMap<Integer,Integer> favouriteBookCount=new HashMap<Integer,Integer>();
        for (int i = 0; i < n; i++) {
            favBook[i] = sc.nextInt();
            favouriteBookCount[favBook[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (favouriteBookCount[favBook[i]] == 1) {
                System.out.println("BeiJu");
            } else if (favouriteBookCount[favBook[i]] > 1) {
                System.out.println(favouriteBookCount[favBook[i]] - 1);
            }
        }
        sc.close();
    }
}
