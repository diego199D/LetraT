package Colas;
import Extras.VectorNbits;

public class ColaB {

    int cabeza;
    int fina;
    VectorNbits V;
    
    public ColaB(int cant, int nBits){
        V = new VectorNbits(cant, nBits);
        cabeza = 0;
        fina = 0;
    }
    
    public boolean vacia(){
        return cabeza == 0;
    }
    
    public boolean llena(){
        return (fina+1)%V.cant == cabeza;
    }
    
    public void encolar(int elem){
        if(vacia()){
            cabeza = 1;
            fina = 1;
            V.insertar(elem, fina);
        }else{
            if(llena()){
                System.out.println("la cola esta llena");
                System.exit(1);
            }else{
                fina = (fina+1) % V.cant;
                V.insertar(elem, fina);
            }
        }
    }
    
    public int decolar(){
        int x = V.sacar(cabeza);
        if(cabeza == fina){
            cabeza = 0;
            fina = 0;
        }
        cabeza = (cabeza+1)%V.cant;
        return x;
    }
    
    public int get(){
        return V.sacar(cabeza);
    }
    
    @Override
    public String toString(){
        String S = "Cola->[ ";
        int aux = cabeza;
        while(aux != fina){
            S = S + V.sacar(aux) + ", ";
            aux = (aux+1)%V.cant;
        }
        return S + V.sacar(aux);
    }
}
