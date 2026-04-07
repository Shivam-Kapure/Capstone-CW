package Inheritance;

public class Puppy extends Dog {
    void weep() {
        System.out.println("puppy weep");
    }
    public static void main(String[] args) {
        Puppy obj = new Puppy();
        obj.weep();
        obj.bark();
        obj.eat();
    }
}
