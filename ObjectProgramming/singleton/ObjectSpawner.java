package ObjectProgramming.singleton;

// ObjectSpawner类 用于演示
import java.util.*;

public class ObjectSpawner {

    public static void main(String[] args) {
        List<X> objList = new ArrayList<X>();
        Class<? extends X> classType;
        objList.add(Factory.create("A"));
        objList.add(Factory.create("B"));
        objList.add(Factory.create("C"));
        for (int i = 0; i < objList.size(); i++) {
            classType = objList.get(i).getClass();
            System.out.printf("Class: %s, ID:", classType.getName());
            if (classType.getName().equals("ObjectProgramming.singleton.A")) {
                A tempA = (A) objList.get(i);
                System.out.printf("%d\n", tempA.id);
            } else if (classType.getName().equals("ObjectProgramming.singleton.B")) {
                B tempB = (B) objList.get(i);
                System.out.printf("%d\n", tempB.id);
            } else if (classType.getName().equals("ObjectProgramming.singleton.C")) {
                C tempC = (C) objList.get(i);
                System.out.printf("%d\n", tempC.id);
            }
        }
    }
}
