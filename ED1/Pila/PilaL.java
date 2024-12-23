package Pilas;

import Extras.Nodo;

public class PilaL {

    int cant;
    Nodo cima;

    public PilaL() {
        cima = null;
        cant = 0;
    }

    public boolean vacia() {
        return cima == null;
    }

    public void push(int elem) {
        Nodo nuevo = new Nodo();
        nuevo.setDato(elem);
        nuevo.setEnlace(cima);
        cima = nuevo;
        cant ++;
    }

    public int pop() {
        if (!vacia()) {
            int x = cima.getDato();
            cima = cima.getEnlace();
            cant --;
            return x;
        }
        return 0;
    }

    public int get() {
        return cima.getDato();
    }

    @Override
    public String toString() {
        String S = "[PILA]" + "\n";
        Nodo aux = cima;
        while (aux != null) {
            S = S + "[ " + aux.getDato() + " ]" + "\n";
            aux = aux.getEnlace();
        }
        return S;
    }
}
