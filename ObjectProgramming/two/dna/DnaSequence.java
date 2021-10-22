package ObjectProgramming.two.dna;

//DNA序列
import java.util.*;

public class DnaSequence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String seq = sc.next(), maxStr = "";
        int minSubstrLen = sc.nextInt(), count;
        sc.close();
        double maxRatio = 0.0;
        for (int i = 0; i <= seq.length() - minSubstrLen; i++) {
            for (int j = i + minSubstrLen; j <= seq.length(); j++) {
                count = 0;
                for (int k = i; k < j; k++) {
                    if (seq.charAt(k) == 'G' || seq.charAt(k) == 'C') {
                        count++;
                    }
                }
                if (count * 1.0 / (j - i) > maxRatio) {
                    maxRatio = count * 1.0 / (j - i);
                    maxStr = seq.substring(i, j);
                }
            }
        }
        System.out.printf("%s", maxStr);
    }
}
