package estudos;
public class Main{
    public static void main(String[] args){

        Personagem heroi = new Personagem();
        heroi.nome = "Hercules";
        heroi.classe = "Semideus";
        heroi.forca = 25;

        System.out.println("O meu personagem e " + heroi.nome + " de classe " + heroi.classe + " e forca de " + heroi.forca);
}

}