package br.edu.femass.exec;

import br.edu.femass.model.Quadrado;
import br.edu.femass.model.SegmentoReta;

public class QuadradoExec {
    public static void main(String[] args) {
        Quadrado q = new Quadrado(new SegmentoReta(0.0, 0.0, 2.0, 2.0));
        System.out.println(q.getarea());
        System.out.println(q.getPerimetro());
    }
}
