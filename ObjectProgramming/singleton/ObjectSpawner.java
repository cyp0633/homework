package ObjectProgramming.singleton;

// ObjectSpawner类 用于演示
import java.util.*;

public class ObjectSpawner {

    public static void main(String[] args) {
        List<X> objList=new ArrayList<X>();
        objList.add(Factory.create("A"));
        objList.add(Factory.create("B"));
        for(int i=0;i<objList.size();i++){
            System.out.printf("Class: %s, ID: %d\n",objList.get(i).getClass(),objList.get(i).id);
        }
    }
}
