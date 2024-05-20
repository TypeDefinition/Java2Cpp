import java.util.List;

public class Main {
    class Animal {};

    class Bird extends Animal { public void walk() {} }
    class Crow extends Bird { public void fly() {} }
    class Penguin extends Bird { public void swim() {} }

    public void foo(List<? super Penguin> list) {
        list.add(new Penguin()); // OK!
        list.getLast().swim(); // Cannot compile.
    }

    public void bar(List<? extends Bird> list) { // Readonly
        list.add(new Bird()); // Cannot compile.
        list.getLast().walk(); // OK!
    }
}

