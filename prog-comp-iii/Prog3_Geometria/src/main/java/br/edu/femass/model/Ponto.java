package br.edu.femass.model;

public class Ponto {
    private Double x, y;


    public Ponto(Double x, Double y) {
        this.x = x;
        this.y = y;
    }

    public Double getX() {
        return x;
    }

    public Double getY() {
        return y;
    }

    public String getLocalizacao(){
        if (this.x>0 && this.y>0) return "1o Quadrante";
        if (this.x<0 && this.y>0) return "2o Quadrante";
        if (this.x<0 && this.y<0) return "3o Quadrante";
        if (this.x>0 && this.y<0) return "4o Quadrante";
        if (this.x!=0 && this.y==0) return "Eixo de X";
        if (this.x==0 && this.y!=0) return "Eixo de Y";
        return "Origem";
    }

    public Double getDistancia(Ponto ponto){
        return Math.sqrt(Math.pow(ponto.getX() - this.x, 2) + Math.pow(ponto.getY() - this.y, 2));
    }

    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }
}