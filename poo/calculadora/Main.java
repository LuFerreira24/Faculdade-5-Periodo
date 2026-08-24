package calculadora;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("---- CALCULADORA ----");
      System.out.println();

                System.out.print("Digite o primeiro numero: ");
        double numero1 = sc.nextDouble();

         System.out.print("Digite o segundo numero: ");
        double numero2 = sc.nextDouble();

        Calcular calcular = new Calcular(numero1, numero2);

      System.out.println();
                System.out.println("---- RESULTADOS ----");
                      System.out.println();

        System.out.println("Soma: " + calcular.soma());

        System.out.println("Subtracao: " + calcular.subtracao());

        System.out.println("Multiplicacao: " + calcular.multiplicacao());

        System.out.println("Divisao: " + calcular.divisao());

        System.out.println("Raiz Quadrada do Primeiro Numero: " + calcular.raizQuadrada());
    }
    
}