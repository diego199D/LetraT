#include <GL/glut.h>

float anguloX = 0.0f;
float anguloY = 0.0f;
float anguloZ = 0.0f;

void iniciar() {
    glEnable(GL_DEPTH_TEST);  // Habilitar prueba de profundidad
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Fondo negro

    // Deshabilitar iluminación para ver los colores originales
    glDisable(GL_LIGHTING);

    // Habilitar sombreado plano
    glShadeModel(GL_FLAT);
}

void dibujarRectanguloVertical() {
    glBegin(GL_QUADS);

    // Cara frontal (Z+)
    glColor3f(1.0f, 0.0f, 0.0f);  // Rojo
    glVertex3f(-0.1f, -0.5f, 0.1f);
    glVertex3f(0.1f, -0.5f, 0.1f);
    glVertex3f(0.1f, 0.3f, 0.1f);
    glVertex3f(-0.1f, 0.3f, 0.1f);

    // Cara trasera (Z-)
    glColor3f(0.0f, 1.0f, 0.0f);  // Verde
    glVertex3f(-0.1f, -0.5f, -0.1f);
    glVertex3f(-0.1f, 0.3f, -0.1f);
    glVertex3f(0.1f, 0.3f, -0.1f);
    glVertex3f(0.1f, -0.5f, -0.1f);

    // Cara izquierda (X-)
    glColor3f(0.0f, 0.0f, 1.0f);  // Azul
    glVertex3f(-0.1f, -0.5f, -0.1f);
    glVertex3f(-0.1f, -0.5f, 0.1f);
    glVertex3f(-0.1f, 0.3f, 0.1f);
    glVertex3f(-0.1f, 0.3f, -0.1f);

    // Cara derecha (X+)
    glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo
    glVertex3f(0.1f, -0.5f, -0.1f);
    glVertex3f(0.1f, 0.3f, -0.1f);
    glVertex3f(0.1f, 0.3f, 0.1f);
    glVertex3f(0.1f, -0.5f, 0.1f);

    // Cara superior (Y+)
    glColor3f(0.0f, 1.0f, 1.0f);  // Cian
    glVertex3f(-0.1f, 0.3f, -0.1f);
    glVertex3f(-0.1f, 0.3f, 0.1f);
    glVertex3f(0.1f, 0.3f, 0.1f);
    glVertex3f(0.1f, 0.3f, -0.1f);

    // Cara inferior (Y-)
    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    glVertex3f(-0.1f, -0.5f, -0.1f);
    glVertex3f(0.1f, -0.5f, -0.1f);
    glVertex3f(0.1f, -0.5f, 0.1f);
    glVertex3f(-0.1f, -0.5f, 0.1f);

    glEnd();
}

void dibujarRectanguloHorizontal() {
    glBegin(GL_QUADS);

    // Cara frontal (Z+)
    glColor3f(1.0f, 0.0f, 0.0f);  // Rojo
    glVertex3f(-0.5f, 0.3f, 0.1f);
    glVertex3f(0.5f, 0.3f, 0.1f);
    glVertex3f(0.5f, 0.1f, 0.1f);
    glVertex3f(-0.5f, 0.1f, 0.1f);

    // Cara trasera (Z-)
    glColor3f(0.0f, 1.0f, 0.0f);  // Verde
    glVertex3f(-0.5f, 0.3f, -0.1f);
    glVertex3f(-0.5f, 0.1f, -0.1f);
    glVertex3f(0.5f, 0.1f, -0.1f);
    glVertex3f(0.5f, 0.3f, -0.1f);

    // Cara izquierda (X-)
    glColor3f(0.0f, 0.0f, 1.0f);  // Azul
    glVertex3f(-0.5f, 0.3f, -0.1f);
    glVertex3f(-0.5f, 0.3f, 0.1f);
    glVertex3f(-0.5f, 0.1f, 0.1f);
    glVertex3f(-0.5f, 0.1f, -0.1f);

    // Cara derecha (X+)
    glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo
    glVertex3f(0.5f, 0.3f, -0.1f);
    glVertex3f(0.5f, 0.1f, -0.1f);
    glVertex3f(0.5f, 0.1f, 0.1f);
    glVertex3f(0.5f, 0.3f, 0.1f);

    // Cara superior (Y+)
    glColor3f(0.0f, 1.0f, 1.0f);  // Cian
    glVertex3f(-0.5f, 0.3f, -0.1f);
    glVertex3f(-0.5f, 0.3f, 0.1f);
    glVertex3f(0.5f, 0.3f, 0.1f);
    glVertex3f(0.5f, 0.3f, -0.1f);

    // Cara inferior (Y-)
    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
    glVertex3f(-0.5f, 0.1f, -0.1f);
    glVertex3f(-0.5f, 0.1f, 0.1f);
    glVertex3f(0.5f, 0.1f, 0.1f);
    glVertex3f(0.5f, 0.1f, -0.1f);

    glEnd();
}

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 3.0,  // Posición de la cámara
        0.0, 0.0, 0.0,  // Punto al que la cámara mira
        0.0, 1.0, 0.0); // Vector arriba

    glRotatef(anguloX, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloY, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloZ, 0.0f, 0.0f, 1.0f);

    dibujarRectanguloVertical();
    dibujarRectanguloHorizontal();

    glutSwapBuffers();
}

void redimensionar(int ancho, int alto) {
    if (alto == 0) alto = 1;
    float relacionAspecto = (float)ancho / (float)alto;

    glViewport(0, 0, ancho, alto);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, relacionAspecto, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void tecladoEspecial(int tecla, int x, int y) {
    switch (tecla) {
    case GLUT_KEY_RIGHT:
        anguloY += 5.0f;
        break;
    case GLUT_KEY_LEFT:
        anguloY -= 5.0f;
        break;
    case GLUT_KEY_UP:
        anguloX -= 5.0f;
        break;
    case GLUT_KEY_DOWN:
        anguloX += 5.0f;
        break;
    case GLUT_KEY_F1:
        anguloZ += 5.0f;
        break;
    case GLUT_KEY_F2:
        anguloZ -= 5.0f;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tarea de Programacion Grafica #1");

    iniciar();

    glutDisplayFunc(mostrar);
    glutReshapeFunc(redimensionar);
    glutSpecialFunc(tecladoEspecial);

    glutMainLoop();
    return 0;
}

