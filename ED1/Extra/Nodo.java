package Extras;

public class Nodo {
    int dato;
    Nodo enlace;
    
    public Nodo(){
        enlace = null;
    }

    public void setDato(int dato) {
        this.dato = dato;
    }

    public void setEnlace(Nodo enlace) {
        this.enlace = enlace;
    }

    public int getDato() {
        return dato;
    }

    public Nodo getEnlace() {
        return enlace;
    }
    
    @Override
    public String toString(){
        return dato + "";
    }
}
