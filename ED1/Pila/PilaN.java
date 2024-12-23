package Pilas;

public class PilaN {

    int V[];
    int cima;

    public PilaN(int cant) {
        V = new int[cant];
        this.cima = -1;
    }

    public boolean vacia() {
        return cima == -1;
    }

    public boolean llena() {
        return cima == V.length - 1;
    }

    public void push(int elem) {
        if (!llena()) {
            cima++;
            V[cima] = elem;
        }
    }

    public int pop() {
        if (!vacia()) {
            cima--;
            return V[cima + 1];
        }
        return 0;
    }

    public int get() {
        return V[cima];
    }

    //Metodos practicados///////*********************************************
    public void eliminarRepetidos() {
        int c = 0;
        PilaN Q = new PilaN(cima + 1);

        while (!vacia() && (c != cima + 1)) {
            int pivote = pop();
            while (!vacia() && cima >= c) {
                int x = pop();
                if (x != pivote) {
                    Q.push(x);
                }
            }
            push(pivote);
            while (!Q.vacia()) {
                push(Q.pop());
            }
            c++;
        }
    }

    ////////
    public void eliminarRepetidosP(){
      PilaN aux = new PilaN(cima+1);
      int x , cont ; 
      int j=0; 
      while(j<=cima){
          cont =0; 
          while(!vacia()){
               aux.push(pop());
          }
          x=aux.pop(); 
          while(!aux.vacia()){
              if (x!=aux.get()) {
                  push(aux.pop());
              }else{
                  cont++; 
                  aux.pop();
              }
          }
          if (cont==0) {
              push(x);
          }
          j++;
      }
    }
    
    
    
    public void eliminarRepetidoYsi() {
        boolean bandera = false;
        int c = 0;
        PilaN Q = new PilaN(cima + 1);
        while (!vacia() && (c != cima + 1)) {
            bandera = false;
            int pivote = pop();
            while (!vacia() && cima >= c) {
                int x = pop();
                if (x != pivote) {
                    Q.push(x);
                } else {
                    bandera = true;
                }
            }
            if (bandera == false) {
                push(pivote);
            }

            while (!Q.vacia()) {
                push(Q.pop());
            }
            c++;
        }
    }

    public int mayor() {
        int c = 0;
        int mayor = 0;
        PilaN Q = new PilaN(cima + 1);
        while (!vacia() && c != cima + 1) {
            int pivote = pop();
            while (!vacia() && c <= cima) {
                int x = pop();
                if (x > mayor) {
                    mayor = x;
                }
                Q.push(x);
            }
            c++;
            push(pivote);
            while (!Q.vacia()) {
                push(Q.pop());
            }
        }
        return mayor;
    }
  
    public int sacarPos(int pos) {
        int posi = pos - 1;
        return V[posi];
    }

    public int sacarPosR(int pos) {
        if (cima == pos - 1) {
            return pop();
        } else {
            int x = pop();
            int y = sacarPosR(pos);
            push(x);
            return y;
        }
    }



    public void partirIntercambiar(){
       int c = 0;
       PilaN Q = new PilaN(cima+1);
       PilaN R = new PilaN(cima+1);
       int total = V.length / 2;
//       if(V.length %2 == 0){
           while (!vacia() && c <= total-1){
               Q.push(pop());
               c++;
           }
           while(!vacia()){
               R.push(pop());
           }
           while(!Q.vacia()){
               push(Q.pop());
           }
           while(!R.vacia()){
               push(R.pop());
           }
//       }else{
//           System.out.println("la pila no tiene cantidad par y no se puede partir");
//       }
    }
    

    ///////////////////////////
    public void intercambiara(PilaN B) {
    PilaN aux = new PilaN((cima + 1) + (B.cima + 1));
    boolean bandera = true;
    while (!vacia() || !B.vacia()) {
        if (!vacia() && bandera==true) {
            aux.push(pop());
            bandera = false;
        } else if (!B.vacia()) {
            aux.push(B.pop());
            bandera = true;
        }
    }
    bandera =false;
    while (!aux.vacia()) {
        if (bandera) {
            B.push(aux.pop());
            bandera = false;
        } else {
            push(aux.pop());
            bandera = true;
        }
    }
}

    
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    @Override
    public String toString() {
        String S = "[PILA]" + "\n";
        for (int i = cima; i >= 0; i--) {
            S = S + "[ " + V[i] + " ]" + "\n";
        }
        return S;
    }

}
