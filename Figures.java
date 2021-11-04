abstract class Figure {
    public abstract double calculateArea();
    public abstract double calculatePerimeter();
}

class Triangle extends Figure implements Printable {
    double a, b, c;

    public Triangle(double a, double b, double c){
        if(a >= b + c || b >= a + c || c >= a + b || a <= 0 || b <= 0 || c <= 0) throw new IllegalArgumentException("Bledna dlugosc bokow");

        this.a = a;
        this.b = b;
        this.c = c;
    }

    public void print() {
        System.out.println("-----------trojkat------------");
        System.out.printf("| Boki: %.2f, %.1f, %.1f \t |%n", a, b, c);
        System.out.printf("| Obwod: %.2f \t\t\t\t |%n", calculatePerimeter());
        System.out.printf("| Pole: %.2f [j^2] \t\t |%n", calculateArea());
        System.out.println("------------------------------");
    }

    @Override
    public double calculateArea() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a)*(s - b)*(s - c));
    }

    @Override
    public double calculatePerimeter() {
        return a + b + c;
    }
}

class  Square extends  Figure implements Printable{
    double a;

    public Square(double a){
        if(a <= 0) throw new IllegalArgumentException("Bledna dlugosc bokow");
        this.a = a;
    }

    public void print(){
        System.out.println("-----------Kwadrat------------");
        System.out.printf("| Boki: %.1f x %.1f \t\t |%n", a, a);
        System.out.printf("| Obwod: %.2f \t\t\t\t |%n", calculatePerimeter());
        System.out.printf("| Pole: %.2f [j^2] \t\t |%n", calculateArea());
        System.out.println("------------------------------");
    }

    @Override
    public double calculateArea(){ return a*a; }

    @Override
    public double calculatePerimeter() { return 4 * a;}
}

class Circle extends  Figure implements Printable{
    double PI = 3.14159265359;
    double r;

    public Circle(double r){
        if(r <= 0) throw new IllegalArgumentException("Bledna dlugosc bokow");
        this.r = r;
    }

    public void print(){
        System.out.println("-------------Kolo-------------");
        System.out.printf("| Promien: %.1f \t\t\t |%n",r);
        System.out.printf("| Obwod: %.2f \t\t\t |%n", calculatePerimeter());
        System.out.printf("| Pole: %.2f [j^2] \t\t |%n", calculateArea());
        System.out.println("------------------------------");
    }

    @Override
    public double calculateArea() {
        return PI * (r * r);}

    @Override
    public double calculatePerimeter() {
        return 2 * PI * r;}
}

class Prism {
    Figure base;
    double h;

    public Prism(Figure base, double h){
        if(h <= 0) throw new IllegalArgumentException("Bledna dlugosc wysokosci");
        this.base = base;
        this.h = h;
    }

    public void print(){
        System.out.println("-------------Graniastoslup-------------");
        System.out.printf("| Wysokosc: %.1f \t\t\t |%n",h);
        System.out.printf("| Pole: %.2f [j^2] \t\t|%n", calculateArea());
        System.out.printf("| Objetosc: %.2f [j^3] \t\t |%n", calculateVolume());
        System.out.println("------------------------------");
    }

    public double calculateArea() {return 2 * base.calculateArea() + base.calculatePerimeter() * h;}

    public double calculateVolume() { return base.calculateArea() * h;}
}