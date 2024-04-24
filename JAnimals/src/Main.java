import java.util.List;

public class Main {
    class Animal {};

    class Insect extends Animal {
        // public void fly() {} // But not all insects fly!
        public void crawl() {}
    }
    class Ant extends Insect {}
    class Ladybird extends Insect {
        public void fly() {}
    }

    class Bird extends Animal {
        public void walk() {}
    }
    class Penguin extends Bird {
        public void swim() {}
    }
    class Gentoo extends Penguin {}
    class Crow extends Bird {
        public void fly() {}
    }

    class Fish extends Animal {
        public void swim() {}
    }

    public void foo(List<? super Bird> list) {
        list.add(new Bird());
        list.getLast().walk(); // Cannot compile.
    }

    public void bar(List<? extends Insect> list) { // Readonly
        list.add(new Insect()); // Cannot compile.
        list.getLast().crawl();
    }

    public <T extends Animal> void baz(T animal) {
        // animal.swim(); // Cannot compile!
    }

    public static void main(String[] args) {
    }
}