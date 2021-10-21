package ObjectProgramming.two.beauty;

//选美比赛
import java.util.*;

class Participant {
    int score;
    int rank;
    int num;
}

class ScoreComparator implements Comparator<Participant> {
    public int compare(Participant a, Participant b) {
        return Integer.compare(a.score, b.score) * -1;
    }
}

class NumComparator implements Comparator<Participant> {
    public int compare(Participant a, Participant b) {
        return Integer.compare(a.num, b.num);
    }
}

public class BeautySelect {
    public static void main(String[] args) {
        int n, rankNum = 1;
        // Participant[] p = new Participant[100];
        Vector<Participant> p = new Vector<Participant>();
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            p.add(new Participant());
            p.elementAt(i).num = i + 1;
            p.elementAt(i).score = sc.nextInt();
        }
        p.sort(new ScoreComparator());
        p.elementAt(0).rank = 1;
        for (int i = 1; i < n; i++) {
            if (p.elementAt(i).score != p.elementAt(i - 1).score) {
                rankNum++;
            }
            p.elementAt(i).rank = rankNum;
        }
        p.sort(new NumComparator());
        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", p.elementAt(i).rank);
        }
        sc.close();
    }
}
