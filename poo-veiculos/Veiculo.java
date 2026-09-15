public class Veiculo {

    String fabricante;
    String modelo;
    int anoFabricacao;
    boolean ligado;

    public Veiculo(String fabricante, String modelo, int anoFabricacao) {
        this.fabricante = fabricante;
        this.modelo = modelo;
        this.anoFabricacao = anoFabricacao;
        this.ligado = false;
    }

    public String getFabricante() {
        return fabricante;
    }

    public String getModelo() {
        return modelo;
    }

    public int getAnoFabricacao() {
        return anoFabricacao;
    }

    public boolean isLigado() {
        return ligado;
    }

    public void setLigado(boolean ligado) {
        this.ligado = ligado;
    }

    public String getInfo() {
        return fabricante + " " + modelo + " " + anoFabricacao + " " + ligado;
    }
}
