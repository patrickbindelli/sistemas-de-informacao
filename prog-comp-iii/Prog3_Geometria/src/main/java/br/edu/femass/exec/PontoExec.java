package br.edu.femass.exec;

import br.edu.femass.model.Ponto;

public class PontoExec {
    public static void main(String[] args) {
        Ponto p1 = new Ponto(2.0,2.0);
        Ponto p2 = new Ponto(0.0,2.0);

        System.out.println(p1.getDistancia(p2));
    }
}
