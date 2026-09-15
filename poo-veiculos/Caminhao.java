public class Caminhao extends Veiculo {

    int numeroEixos;
    double capacidadeMaxima;
    double cargaAtual;

    public Caminhao(String fabricante, String modelo, int anoFabricacao,
                    int numeroEixos, double capacidadeMaxima, double cargaAtual) {

        super(fabricante, modelo, anoFabricacao);

        this.numeroEixos = numeroEixos;
        this.capacidadeMaxima = capacidadeMaxima;
        this.cargaAtual = cargaAtual;
    }

    public void ligaCaminhao() {
        if (!ligado) {
            ligado = true;
            System.out.println("Caminhão ligado!");
        } else {
            System.out.println("O caminhão já está ligado!");
        }
    }

    public void desligaCaminhao() {
        if (ligado) {
            ligado = false;
            System.out.println("Caminhão desligado!");
        } else {
            System.out.println("O caminhão já está desligado!");
        }
    }

    public void insereCarga(double valor) {
        if (cargaAtual + valor <= capacidadeMaxima) {
            cargaAtual += valor;
            System.out.println("Carga inserida!");
        } else {
            System.out.println("Erro: carga máxima ultrapassada!");
        }
    }

    public void removeCarga(double valor) {
        if (valor <= cargaAtual) {
            cargaAtual -= valor;
            System.out.println("Carga removida!");
        } else {
            System.out.println("Erro: carga insuficiente!");
        }
    }

    public String getInfo() {
        return fabricante + " " + modelo + " " + anoFabricacao + " "
                + ligado + " " + numeroEixos + " " + capacidadeMaxima
                + " " + cargaAtual;
    }
}
