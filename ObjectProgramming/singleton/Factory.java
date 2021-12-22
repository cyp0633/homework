package ObjectProgramming.singleton;

public class Factory<T> {
    static int id = 0;

    static final Factory<A> a1 = new Factory<>();
    static final Factory<B> b1 = new Factory<>();
    static final Factory<C> c1 = new Factory<>();

    X createX() {
        if (this == a1) {
            System.out.printf("Creating an A\n");
            return new A(id);
        } else if (this == b1) {
            System.out.printf("Creating a B\n");
            return new B(id);
        } else if (this == c1) {
            System.out.printf("Creating a C\n");
            return new C(id);
        } else {
            id -= 1;
            return null;
        }
    }

    public static X create(String s) {
        X temp = null;
        id += 1;
        if (s.equals("A")) {
            temp = a1.createX();
            ((A) temp).id = id;
        } else if (s.equals("B")) {
            temp = b1.createX();
            ((B) temp).id = id;
        } else if (s.equals("C")) {
            temp = c1.createX();
            ((C) temp).id = id;
        }
        if (temp == null)
            id -= 1;
        return temp;
    }
}