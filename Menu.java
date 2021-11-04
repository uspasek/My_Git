import java.nio.channels.ShutdownChannelGroupException;
import java.util.Scanner;
import java.util.stream.Stream;

public class Menu {
    Scanner scanner = new Scanner(System.in);
    String header = "\n+           Calculator                 +";
    String footer = "+                                     +";
    String separator = "+                                  +";
    String body1 = "| 1. Trojkat\t\t\t\t\t\t|\n| 2. Kwadrat \t\t\t\t\t\t|\n| 3. Kolo\t\t\t\t\t\t\t|\n| 4. Graniastoslup prawidlowy\t\t|\n| 5. Wyjdz \t\t\t\t\t\t\t|\n|\t\t\t\t\t\t\t\t\t|";
    String body2 = "| 1. Oblicz pole\t\t\t\t\t|\n| 2. Oblicz obwod\t\t\t\t\t|\n| 3. Wroc\t\t\t\t\t\t\t|\n|";
    String body3 = "| 1. Oblicz pole\t\t\t\t|\n| 2. Oblicz objetosc\t\t\t\t\t|\n| 3. Wroc\t\t\t\t\t\t\t\t|\n";
    Figure figure;
    int option;
    boolean userEnded = false;

    public void mainMenu() {
        System.out.println(header);
        System.out.println(footer);
        System.out.println(body1);
        System.out.println(footer);
        option = scanner.nextInt();
        System.out.println((header));
    }

    public void triangleMenu(){
        System.out.println("| Wprowadz dlugosci bokow [a b c]: |");
        System.out.printf("| ");
        double[] data = new double[3];

        for (int i = 0; i < 3; i++){
            data[i] = scanner.nextDouble();
        }

        figure = new Triangle(data[0], data[1], data[2]);
        System.out.println((separator));
        System.out.printf(body2);
        System.out.println(footer);

        option = scanner.nextInt();
        System.out.println(header);

        if(option == 1) {
            System.out.println(figure.calculateArea());
            System.out.println(footer);
        }else if(option == 2){
            System.out.printf("| ");
            System.out.println(figure.calculatePerimeter());
            System.out.printf("\t\t |");
            System.out.println((footer));
        }
        mainMenu();
    }

    public void squareMenu(){
        System.out.println("| Wprowadz dlugosci boku [a]: |");
        System.out.printf("| ");
        double[] data = new double[1];

        for (int i = 0; i < 1; i++){
            data[i] = scanner.nextDouble();
        }

        figure = new Square(data[0]);
        System.out.println((separator));
        System.out.printf(body2);
        System.out.println(footer);

        option = scanner.nextInt();
        System.out.println(header);

        if(option == 1) {
            System.out.println(figure.calculateArea());
            System.out.println(footer);
        }else if(option == 2){
            System.out.printf("| ");
            System.out.println(figure.calculatePerimeter());
            System.out.printf("\t\t |");
            System.out.println((footer));
        }
        mainMenu();
    }
    public void circleMenu(){
        System.out.println("| Wprowadz dlugosci promienia [r]: |");
        System.out.printf("| ");
        double[] data = new double[1];

        for (int i = 0; i < 1; i++){
            data[i] = scanner.nextDouble();
        }

        figure = new Circle(data[0]);
        System.out.println((separator));
        System.out.printf(body2);
        System.out.println(footer);

        option = scanner.nextInt();
        System.out.println(header);

        if(option == 1) {
            System.out.println(figure.calculateArea());
            System.out.println(footer);
        }else if(option == 2){
            System.out.printf("| ");
            System.out.println(figure.calculatePerimeter());
            System.out.printf("\t\t |");
            System.out.println((footer));
        }
        mainMenu();
    }
    public void prismSubMenu(){
        System.out.println("| Wprowadz wysokosc [h]:           |");
        double h = scanner.nextDouble();

        Prism prism = new Prism(figure, h);
        System.out.println(header);
        System.out.printf(body3);
        System.out.println(footer);
        option = scanner.nextInt();

        if(option == 1){
            System.out.println(prism.calculateArea());
            System.out.printf(footer);
        }else if (option == 2 ){
            System.out.println((prism.calculateVolume()));
            System.out.printf(footer);
        }else {
            prismMenu();
        }
    }
    public void prismMenu() {
        System.out.println("| Wybierz podstawe: \t\t\t\t|");
        System.out.printf("| 1. Trojkat\t\t\t\t\t\t|\n| 2. Kwadrat \t\t\t\t\t\t|\n| 3. Kolo\t\t\t\t\t\t\t|\n| 4. Wroc\t\t\t\t\t|\n|");
        System.out.printf(footer);
        System.out.printf("\n| ");
        option = scanner.nextInt();

        switch (option){
            //trojkat
            case 1:
                System.out.println("| Wprowadz boki podstawy [a b c]:   |");
                System.out.printf("| ");
                double[] data = new double[3];
                for (int i = 0; i < 3; i++){
                    data[i] = scanner.nextDouble();
                }
                figure = new Triangle(data[0], data[1], data[2]);
                prismSubMenu();
                break;
                // kwadrat
            case 2:
                System.out.println("| Wprowadz bok podstawy [a]:   |");
                System.out.printf("| ");
                data = new double[1];
                for (int i = 0; i < 1; i++){
                    data[i] = scanner.nextDouble();
                }
                figure = new Square(data[0]);
                prismSubMenu();
                break;
                //Kolo
            case 3:
                System.out.println("| Wprowadz promien [r]:     |");
                System.out.printf("| ");
                data = new double[1];
                for (int i = 0; i < 1; i++){
                    data[i] = scanner.nextDouble();
                }
                figure = new Circle(data[0]);
                prismSubMenu();
                break;
                // Wroc
            case 4:
                mainMenu();
                break;

        }
    }
}
