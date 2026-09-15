public class Main {
    public static void main(String[] args) {

        System.out.println("--- Testando Carro ---");
        Carro carro = new Carro("Fiat", "Argo", 2022, 4, 5);
        carro.ligaCarro();
        carro.ligaCarro();
        System.out.println(carro.getInfo());
        carro.desligaCarro();
        System.out.println(carro.getInfo());

        System.out.println("\n--- Testando Caminhao ---");
        Caminhao caminhao = new Caminhao("Volvo", "FH", 2020, 3, 1000.0, 0.0);
        caminhao.ligaCaminhao();
        caminhao.insereCarga(500.0);
        caminhao.insereCarga(600.0); // deve dar erro (ultrapassa capacidade)
        caminhao.removeCarga(200.0);
        System.out.println(caminhao.getInfo());

        System.out.println("\n--- Testando Moto ---");
        Moto moto = new Moto("Honda", "CG 160", 2023, 15.0, 0.0, "Preta");
        moto.ligaMoto();
        moto.insereCarga(10.0);
        moto.insereCarga(10.0); // deve dar erro (ultrapassa volume)
        moto.removeCarga(5.0);
        System.out.println(moto.getInfo());
    }
}
