package ObjectProgramming.three.rearrange;

//去重与排序
import java.util.*;

public class Rearrange {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SortedSet<Integer> numSet = new TreeSet<>();
        int n, num = 0;
        while (sc.hasNextInt()) {
            n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                num = sc.nextInt();
                numSet.add(num);
            }
            Iterator<Integer> it = numSet.iterator();
            while (it.hasNext()) {
                System.out.printf("%d ", it.next());
            }
        }
        sc.close();
    }
}
