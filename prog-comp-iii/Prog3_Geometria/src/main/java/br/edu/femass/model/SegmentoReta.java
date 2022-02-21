package br.edu.femass.model;

public class SegmentoReta {
    private Ponto p1, p2;

    public SegmentoReta(Ponto p1, Ponto p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    public SegmentoReta(Double x1, Double y1, Double x2, Double y2) {
        this.p1 = new Ponto(x1, y1);
        this.p2 =  new Ponto(x2, y2);
    }

    public Ponto getP1() {
        return p1;
    }

    public Ponto getP2() {
        return p2;
    }

    public  Double getTamanho(){
        return this.p1.getDistancia(this.p2);
    }

    public String toString() {
        return this.p1.toString() + " - " + this.p2.toString();
    }
}
