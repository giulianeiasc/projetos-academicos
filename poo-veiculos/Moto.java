public class Moto extends Veiculo {

    double volumeCompartimento;
    double volumeEmUso;
    String cor;

    public Moto(String fabricante, String modelo, int anoFabricacao,
                double volumeCompartimento, double volumeEmUso, String cor) {

        super(fabricante, modelo, anoFabricacao);

        this.volumeCompartimento = volumeCompartimento;
        this.volumeEmUso = volumeEmUso;
        this.cor = cor;
    }

    public void ligaMoto() {
        if (!ligado) {
            ligado = true;
            System.out.println("Moto ligada!");
        } else {
            System.out.println("A moto já está ligada!");
        }
    }

    public void desligaMoto() {
        if (ligado) {
            ligado = false;
            System.out.println("Moto desligada!");
        } else {
            System.out.println("A moto já está desligada!");
        }
    }

    public void insereCarga(double valor) {
        if (volumeEmUso + valor <= volumeCompartimento) {
            volumeEmUso += valor;
            System.out.println("Carga inserida!");
        } else {
            System.out.println("Erro: volume máximo ultrapassado!");
        }
    }

    public void removeCarga(double valor) {
        if (valor <= volumeEmUso) {
            volumeEmUso -= valor;
            System.out.println("Carga removida!");
        } else {
            System.out.println("Erro: volume insuficiente!");
        }
    }

    public String getInfo() {
        return fabricante + " " + modelo + " " + anoFabricacao + " "
                + ligado + " " + volumeCompartimento + " "
                + volumeEmUso + " " + cor;
    }
}
