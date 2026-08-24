package calculadora;

public class Calcular {

    double numero1, numero2;
    
    Calcular(double numero1, double numero2){
    this.numero1 = numero1;
    this.numero2 = numero2;
    }

    public double soma(){
        return numero1 + numero2;
    }

       public double subtracao(){
        return numero1 - numero2;
    }

           public double multiplicacao(){
        return numero1 * numero2;
}

           public double divisao(){
        return numero1 / numero2;
}

           public double raizQuadrada(){
        return Math.sqrt(numero1);
}

}
