package ObjectProgramming.two.dice;

//骰子问题旋转（李氏中文？）
import java.util.*;

public class RollingDice {
    static int front = 3, back = 4, top = 5, bott = 6, left = 1, right = 2;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        sc.close();
        char ch;
        for (int i = 0; i < str.length(); i++) {
            ch = str.charAt(i);
            switch (ch) {
            case 'L':
                LeftRotate();
                break;
            case 'R':
                RightRotate();
                break;
            case 'F':
                FrontRotate();
                break;
            case 'B':
                BackRotate();
                break;
            case 'A':
                CounterClockwiseRotate();
                break;
            case 'C':
                ClockwiseRotate();
            }
        }
        System.out.printf("%d %d %d %d %d %d", left, right, front, back, top, bott);
    }

    static void LeftRotate() {
        int temp = left;
        left = top;
        top = right;
        right = bott;
        bott = temp;
    }

    static void RightRotate() {
        int temp = left;
        left = bott;
        bott = right;
        right = top;
        top = temp;
    }

    static void FrontRotate() {
        int temp = front;
        front = top;
        top = back;
        back = bott;
        bott = temp;
    }

    static void BackRotate() {
        int temp = back;
        back = top;
        top = front;
        front = bott;
        bott = temp;
    }

    static void CounterClockwiseRotate() {
        int temp = left;
        left = back;
        back = right;
        right = front;
        front = temp;
    }

    static void ClockwiseRotate() {
        int temp = front;
        front = right;
        right = back;
        back = left;
        left = temp;
    }
}
