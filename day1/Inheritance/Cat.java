package Inheritance;

public class Cat extends Animal {
    void meow() {
        System.out.println("cat meoww....");
    }
    public static void main(String[] args) {
        Cat obj = new Cat();
        obj.meow();
        obj.eat();
    }
}