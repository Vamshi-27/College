#include <stdio.h>
#include <GL/glut.h>

void myinit();
void display();

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Simple OpenGL Program");
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    glPointSize(10.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(90, 90);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(10, 10);
    glVertex2i(90, 10);
    glVertex2i(10, 90);
    glVertex2i(90, 90);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(20, 30);
    glVertex2i(25, 70);
    glVertex2i(40, 55);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(40, 60);
    glVertex2i(60, 80);
    glVertex2i(80, 40);
    glEnd();
    glFlush();
}