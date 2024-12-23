package Colas;

public class ColaV {

    int V[];
    int cabeza;
    int fina;

    public ColaV(int cant) {
        V = new int[cant];
        cabeza = -1;
        fina = -1;
    }

    public boolean vacia() {
        return cabeza == -1;
    }

    public boolean llena() {
        return (fina + 1) % V.length == cabeza;
    }

    public void encolar(int elem) {
        if (vacia()) {
            cabeza = 0;
            fina = 0;
            V[fina] = elem;
        } else {
            if (llena()) {
                System.out.println("La Cola esta llena");
                System.exit(1);
            } else {
                fina = (fina + 1) % V.length;
                V[fina] = elem;
            }
        }
    }

    public int decolar() {
        int x = V[cabeza];
        if (cabeza == fina) {
            cabeza = -1;
            fina = -1;
        } else {
            cabeza = (cabeza + 1) % V.length;
        }
        return x;
    }

    public int get() {
        return V[cabeza];
    }

    @Override
    public String toString() {
        String S = "C->[ ";
        int aux = cabeza;
        while (aux != fina) {
            S = S + V[aux] + ", ";
            aux = (aux + 1) % V.length;
        }
        return S + V[aux] + " ]";
    }
}
