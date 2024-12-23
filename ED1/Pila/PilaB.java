package Pilas;

import Extras.VectorNbits;

public class PilaB {

    VectorNbits V;
    int cima;

    public PilaB(int cant, int nBits) {
        V = new VectorNbits(cant, nBits);
        cima = 0;
    }

    public boolean vacia() {
        return cima == 0;
    }
    
    public boolean llena(){
        return cima == V.cant;
    }
    
    public void push(int elem){
        if(!llena()){
            cima++;
            V.insertar(elem, cima);
        }
    }
    
    public int pop(){
        if(!vacia()){
            int x = V.sacar(cima);
            cima --;
            return x;
        }
        return 0;
    }
    
    @Override
    public String toString(){
        String S = "[ PILA ]" + "\n";
        for(int i = cima; i >= 1; i--){
            S = S + "[ " + V.sacar(i) + " ]" + "\n";
        }
        return S;
    }
}
