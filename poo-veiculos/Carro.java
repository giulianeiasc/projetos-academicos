public class Carro extends Veiculo {

    int numeroPortas;
    int quantidadeLugares;

    public Carro(String fabricante, String modelo, int anoFabricacao,
                 int numeroPortas, int quantidadeLugares) {

        super(fabricante, modelo, anoFabricacao);

        this.numeroPortas = numeroPortas;
        this.quantidadeLugares = quantidadeLugares;
    }

    public void ligaCarro() {
        if (!ligado) {
            ligado = true;
            System.out.println("Carro ligado!");
        } else {
            System.out.println("O carro já está ligado!");
        }
    }

    public void desligaCarro() {
        if (ligado) {
            ligado = false;
            System.out.println("Carro desligado!");
        } else {
            System.out.println("O carro já está desligado!");
        }
    }

    public String getInfo() {
        return fabricante + " " + modelo + " " + anoFabricacao + " "
                + ligado + " " + numeroPortas + " " + quantidadeLugares;
    }
}
