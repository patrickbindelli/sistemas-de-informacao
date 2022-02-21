package br.edu.femass.model;

public class Quadrado {
    protected SegmentoReta lado;

    public SegmentoReta getLado() {
        return lado;
    }

    public Quadrado(SegmentoReta lado) {
        this.lado = lado;
    }

    public Double getPerimetro(){
        return this.lado.getTamanho() * 4.0;
    }

    public Double getarea(){
        return Math.pow(this.lado.getTamanho(), 2.0);
    }
}
