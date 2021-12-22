package ObjectProgramming.singleton;

public class Factory<T> {
    int id=0;

    static final Factory<A> a1 = new Factory<>();
    static final Factory<B> b1 = new Factory<>();
    static final Factory<C> c1 = new Factory<>();

    X createX() {
        id+=1;
        if (this == a1) {
            System.out.printf("Creating an A\n");
            return new A(id);
        } else if (this == b1) {
            System.out.printf("Creating a B\n");
            return new B(id);
        } else if (this == c1) {
            System.out.printf("Creating a C\n");
            return new C(id);
        } else{
            id-=1;
            return null;
        }
    }

    public static X create(String s) {
        if (s.equals("A"))
            return a1.createX();
        else if (s.equals("B"))
            return b1.createX();
        else if (s.equals("C"))
            return c1.createX();
        else
            return null;
    }

    // public static void get(String[] args) {
    //     Factory<?> f1 = Factory.create("A");
    //     f1.createX();
    //     Factory<?> f2 = Factory.create("B");
    //     f2.createX();
    //     Factory<?> f3 = Factory.create("C");
    //     f3.createX();
    // }
}