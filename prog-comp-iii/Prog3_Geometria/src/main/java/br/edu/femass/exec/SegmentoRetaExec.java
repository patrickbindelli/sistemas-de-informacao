package br.edu.femass.exec;

import br.edu.femass.model.SegmentoReta;

public class SegmentoRetaExec {
    public static void main(String[] args) {
        SegmentoReta sr = new SegmentoReta(0.0, 0.0, 2.0, 2.0);

        System.out.println(sr.getTamanho());
        System.out.println(sr);
    }
}
