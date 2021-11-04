import java.util.Scanner;
import java.util.concurrent.TransferQueue;

class calculator {
    public static  void main(String[] args) {

        consoleUI();
    }

    static void  printExaples() {
        //Triangle triangle = new Triangle()
    }

    public static void consoleUI() {
        Menu menu = new Menu();
        menu.mainMenu();

        do{
            switch (menu.option){
                //trojkat
                case 1:
                    menu.triangleMenu();
                    break;
                //kwadrat
                case 2:
                    menu.squareMenu();
                    break;
                //Kolo
                case 3:
                    menu.circleMenu();
                    break;
                //Graniastoslup
                case 4:
                    menu.prismMenu();
                    break;
                default:
                    menu.userEnded = true;
                    break;
            }
        }while(menu.userEnded == false);

    }
}
