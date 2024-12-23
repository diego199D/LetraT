package Extras;

public class VectorNbits {

    int v[];
    public int cant;
    int cantidadBits;

    public VectorNbits(int numElementos, int cantBits) {
        int numBits = numElementos * cantBits;
        int numEnteros = numBits / 32;
        if ((numBits % 32) != 0) {
            numEnteros++;
        }
        v = new int[numEnteros];
        cant = numElementos;
        cantidadBits = cantBits;
    }

    public void insertar(int ele, int pos) {
        if (pos <= cant) {
            int ele1 = ele;
            int mask = (int) Math.pow(2, cantidadBits) - 1;
            int numBits = calcularBits(pos);
            int numEntero = calcularEntero(pos);
            mask = mask << numBits;
            mask = ~mask;
            v[numEntero] = v[numEntero] & mask;
            ele = ele << numBits;
            v[numEntero] = v[numEntero] | ele;
            if ((numBits + cantidadBits) > 32) {
                int mask1 = (int) Math.pow(2, cantidadBits) - 1;
                mask1 = mask1 >>> (32 - numBits);
                mask1 = ~mask1;
                v[numEntero + 1] = v[numEntero + 1] & mask1;
                ele1 = ele1 >>> (32 - numBits);
                v[numEntero + 1] = v[numEntero + 1] | ele1;
            }
        }
    }

    public int sacar(int pos) {
        int mask = (int) ((Math.pow(2, cantidadBits) - 1));
        int numBits = calcularBits(pos);
        int numEntero = calcularEntero(pos);
        mask = mask << numBits;
        mask = mask & v[numEntero];
        mask = mask >>> numBits;
        if ((numBits + cantidadBits) > 32) {
            int mask1 = (int) ((Math.pow(2, cantidadBits) - 1));
            mask1 = mask1 >>> (32 - numBits);
            mask1 = mask1 & v[numEntero + 1];
            mask1 = mask1 << (32 - numBits);
            mask = mask | mask1;
        }
        return mask;
    }

    private int calcularBits(int pos) {
        return (((pos - 1) * cantidadBits % 32));
    }

    private int calcularEntero(int pos) {
        return ((pos - 1) * cantidadBits / 32);
    }

    @Override
    public String toString() {
        String S = "V=[";
        for (int i = 1; i <= cant; i++) {
            S = S + sacar(i) + " , ";
        }
        S = S.replaceAll(",$", "");
        S = S + "]";
        return S;
    }

}
