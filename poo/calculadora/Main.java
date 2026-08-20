package calculadora;
// ...existing code...
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            Soma objetosoma = new Soma();
            objetosoma.a = sc.nextDouble();
            objetosoma.b = sc.nextDouble();
        }
    }

}