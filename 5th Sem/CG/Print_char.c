#include <stdio.h>
#include <GL/glut.h>

void myinit();
void display();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Simple OpenGL Program");
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glPointSize(10.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /*glRasterPos2i(10, 490);
    glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'C');*/

    glRasterPos2i(0, 480);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'A');

    glFlush();
}
