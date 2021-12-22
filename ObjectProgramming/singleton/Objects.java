package ObjectProgramming.singleton;

class X {
    static int id;
    int id2;
}

class A extends X {
    int id;

    A(int id) {
        this.id = id;
    }

    A() {
        this(0);
    }
}

class B extends X {
    int id;

    B(int id) {
        this.id = id;
    }

    B() {
        this(0);
    }
}

class C extends X {
    int id;

    C(int id) {
        this.id = id;
    }

    C() {
        this(0);
    }
}