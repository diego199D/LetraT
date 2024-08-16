#include <GL/glut.h>

int anguloX = 0;
int anguloY = 0;
int anguloZ = 0;

void iniciar() {
    glEnable(GL_DEPTH_TEST);  // activamos prueba de profundidad
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Letra() {
    glBegin(GL_QUADS);
    //tronco
    //parte frontal
    glColor3f(0.0f, 0.0f, 1.0f);  // azul
    glVertex3i(-1, -5, 1);
    glVertex3i(1, -5, 1);
    glVertex3i(1, 3, 1);
    glVertex3i(-1, 3, 1);

    //parte de atras
    glColor3f(1.0f, 0.0f, 0.0f); //rojo
    glVertex3i(-1, -5, -1);
    glVertex3i(1, -5, -1);
    glVertex3i(1, 3, -1);
    glVertex3i(-1, 3, -1);

    //lateral izquierda
    glColor3f(1.0f, 0.0f, 1.5f); //color lila
    glVertex3i(-1, -5, -1);
    glVertex3i(-1, -5, 1);
    glVertex3i(-1, 3, 1);
    glVertex3i(-1, 3, -1);

    //lateral derecha
    glColor3f(1.0f, 0.0f, 1.5f); //color lila
    glVertex3i(1, -5, -1);
    glVertex3i(1, -5, 1);
    glVertex3i(1, 3, 1);
    glVertex3i(1, 3, -1);

    //tapa de arriba
    glColor3f(1.0f, 1.0f, 0.0f); //color amarillo
    glVertex3i(1, 3, 1);
    glVertex3i(-1, 3, 1);
    glVertex3i(-1, 3, -1);
    glVertex3i(1, 3, -1);

    //tapa de abajo
    glColor3f(1.0f, 1.0f, 0.0f); //color amarillo
    glVertex3i(1, -5, 1);
    glVertex3i(-1, -5, 1);
    glVertex3i(-1, -5, -1);
    glVertex3i(1, -5, -1);


    //Sombrero de la T
    //parte frontal
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3i(-4, 3, 1);
    glVertex3i(-4, 5, 1);
    glVertex3i(4, 5, 1);
    glVertex3i(4, 3, 1);

    //parte tracera
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3i(-4, 3, -1);
    glVertex3i(-4, 5, -1);
    glVertex3i(4, 5, -1);
    glVertex3i(4, 3, -1);

    //tapa de la derecha
    glColor3f(1.0f, 0.0f, 1.5f); //color lila
    glVertex3i(-4, 3, -1);
    glVertex3i(-4, 5, -1);
    glVertex3i(-4, 5, 1);
    glVertex3i(-4, 3, 1);

    //tapa de la izquierda
    glColor3f(1.0f, 0.0f, 1.5f); //color lila
    glVertex3i(4, 3, -1);
    glVertex3i(4, 5, -1);
    glVertex3i(4, 5, 1);
    glVertex3i(4, 3, 1);

    //tapon superior del sombrero
    glColor3f(1.0f, 1.0f, 0.0f); //color amarillo
    glVertex3i(-4, 5, -1);
    glVertex3i(-4, 5, 1);
    glVertex3i(4, 5, 1);
    glVertex3i(4, 5, -1);

    //tapon inferior del sombrero
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3i(-4, 3, -1);
    glVertex3i(-4, 3, 1);
    glVertex3i(4, 3, 1);
    glVertex3i(4, 3, -1);


    glEnd();
}

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0, 0, 20,  // Posición de la cámara
        0, 0, 0,  // Punto al que la cámara mira
        0, 10, 0); // Vector arriba

    glRotatef(anguloX, 1, 0, 0);
    glRotatef(anguloY, 0, 1, 0);
    glRotatef(anguloZ, 0, 0, 1);

    Letra();

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



