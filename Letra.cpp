#include <GL/glut.h>

int anguloX = 0;
int anguloY = 0;
int anguloZ = 0;

void iniciar() {
    glEnable(GL_DEPTH_TEST);  // activamos prueba de profundidad
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Tronco() {
    glBegin(GL_QUADS);

    // Cara frontal (Z+)
    glColor3f(1.0f, 0.0f, 0.0f);  // Rojo
    glVertex3i(-1, -5, 1);  // V�rtice inferior izquierdo
    glVertex3i(1, -5, 1);   // V�rtice inferior derecho
    glVertex3i(1, 3, 1);    // V�rtice superior derecho
    glVertex3i(-1, 3, 1);   // V�rtice superior izquierdo

    // Cara trasera (Z-)
    glColor3f(0.0f, 1.0f, 0.0f);  // Verde
    glVertex3i(-1, -5, -1);  // V�rtice inferior izquierdo
    glVertex3i(-1, 3, -1);   // V�rtice superior izquierdo
    glVertex3i(1, 3, -1);    // V�rtice superior derecho
    glVertex3i(1, -5, -1);   // V�rtice inferior derecho

    // Cara izquierda (X-)
    glColor3f(0.0f, 0.0f, 1.0f);  // Azul
    glVertex3i(-1, -5, -1);  // V�rtice trasero inferior izquierdo
    glVertex3i(-1, -5, 1);   // V�rtice frontal inferior izquierdo
    glVertex3i(-1, 3, 1);    // V�rtice frontal superior izquierdo
    glVertex3i(-1, 3, -1);   // V�rtice trasero superior izquierdo

    // Cara derecha (X+)
    glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo
    glVertex3i(1, -5, -1);  // V�rtice trasero inferior derecho
    glVertex3i(1, 3, -1);   // V�rtice trasero superior derecho
    glVertex3i(1, 3, 1);    // V�rtice frontal superior derecho
    glVertex3i(1, -5, 1);   // V�rtice frontal inferior derecho

    // Cara superior (Y+)
    glColor3f(0.0f, 1.0f, 1.0f);  // Celeste claro
    glVertex3i(-1, 3, -1);  // V�rtice trasero superior izquierdo
    glVertex3i(-1, 3, 1);   // V�rtice frontal superior izquierdo
    glVertex3i(1, 3, 1);    // V�rtice frontal superior derecho
    glVertex3i(1, 3, -1);   // V�rtice trasero superior derecho

    // Cara inferior (Y-)
    glColor3f(1.0f, 0.0f, 1.0f);  // Rosa brillante (fucsia)
    glVertex3i(-1, -5, -1);  // V�rtice trasero inferior izquierdo
    glVertex3i(1, -5, -1);   // V�rtice trasero inferior derecho
    glVertex3i(1, -5, 1);    // V�rtice frontal inferior derecho
    glVertex3i(-1, -5, 1);   // V�rtice frontal inferior izquierdo

    glEnd();

}

void Sombrero() {
    glBegin(GL_QUADS);

    // Cara frontal (Z+)
    glColor3f(1.0f, 0.0f, 0.0f);  // Rojo
    glVertex3i(-5, 3, 1);  // V�rtice superior izquierdo
    glVertex3i(5, 3, 1);   // V�rtice superior derecho
    glVertex3i(5, 1, 1);   // V�rtice inferior derecho
    glVertex3i(-5, 1, 1);  // V�rtice inferior izquierdo

    // Cara trasera (Z-)
    glColor3f(0.0f, 1.0f, 0.0f);  // Verde
    glVertex3i(-5, 3, -1);  // V�rtice superior izquierdo
    glVertex3i(-5, 1, -1);  // V�rtice inferior izquierdo
    glVertex3i(5, 1, -1);   // V�rtice inferior derecho
    glVertex3i(5, 3, -1);   // V�rtice superior derecho

    // Cara izquierda (X-)
    glColor3f(0.0f, 0.0f, 1.0f);  // Azul
    glVertex3i(-5, 3, -1);  // V�rtice trasero superior izquierdo
    glVertex3i(-5, 3, 1);   // V�rtice frontal superior izquierdo
    glVertex3i(-5, 1, 1);   // V�rtice frontal inferior izquierdo
    glVertex3i(-5, 1, -1);  // V�rtice trasero inferior izquierdo

    // Cara derecha (X+)
    glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo
    glVertex3i(5, 3, -1);  // V�rtice trasero superior derecho
    glVertex3i(5, 1, -1);  // V�rtice trasero inferior derecho
    glVertex3i(5, 1, 1);   // V�rtice frontal inferior derecho
    glVertex3i(5, 3, 1);   // V�rtice frontal superior derecho

    // Cara superior (Y+)
    glColor3f(0.0f, 1.0f, 1.0f);  // Celeste claro
    glVertex3i(-5, 3, -1);  // V�rtice trasero superior izquierdo
    glVertex3i(-5, 3, 1);   // V�rtice frontal superior izquierdo
    glVertex3i(5, 3, 1);    // V�rtice frontal superior derecho
    glVertex3i(5, 3, -1);   // V�rtice trasero superior derecho

    // Cara inferior (Y-)
    glColor3f(1.0f, 0.0f, 1.0f);  // Rosa brillante (fucsia)
    glVertex3i(-5, 1, -1);  // V�rtice trasero inferior izquierdo
    glVertex3i(-5, 1, 1);   // V�rtice frontal inferior izquierdo
    glVertex3i(5, 1, 1);    // V�rtice frontal inferior derecho
    glVertex3i(5, 1, -1);   // V�rtice trasero inferior derecho

    glEnd();


}

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0, 0, 20,  // Posici�n de la c�mara
        0, 0, 0,  // Punto al que la c�mara mira
        0, 10, 0); // Vector arriba

    glRotatef(anguloX, 1, 0, 0);
    glRotatef(anguloY, 0, 1, 0);
    glRotatef(anguloZ, 0, 0, 1);

    Tronco();
    Sombrero();

    glutSwapBuffers();
}


void redimensionar(int ancho, int alto) {
    if (alto == 0) {
        alto = 1;
    }
    float relacionAspecto = (float)ancho / (float)alto;

    glViewport(0, 0, ancho, alto); //la T se renderizara en toda la ventana

    glMatrixMode(GL_PROJECTION); //modo de proyeccion en una matriz
    glLoadIdentity(); //limpiar transformaciones
    gluPerspective(35, relacionAspecto, 0.1f, 100.0f); //para la perpectica 

    glMatrixMode(GL_MODELVIEW); //indicar que la matriz estara afectada
    glLoadIdentity(); //modelo de vista reestablecido a estado neutral
}

void moviendoConTeclas(int tecla, int x, int y) {
    switch (tecla) {
    case GLUT_KEY_RIGHT:
        anguloY += 5;
        break;
    case GLUT_KEY_LEFT:
        anguloY -= 5;
        break;
    case GLUT_KEY_UP:
        anguloX -= 5;
        break;
    case GLUT_KEY_DOWN:
        anguloX += 5;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Tarea de Programacion Grafica #1");

    iniciar();

    glutDisplayFunc(mostrar);
    glutReshapeFunc(redimensionar);
    glutSpecialFunc(moviendoConTeclas);

    glutMainLoop();
    return 0;
}



