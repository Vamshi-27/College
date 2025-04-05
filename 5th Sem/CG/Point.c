// Basic Program for displaying points

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
    glPointSize(6.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glVertex2i(30, 80);
    glVertex2i(70, 80);
    glVertex2i(70, 20);
    glVertex2i(30, 20);

    glEnd();
    glBegin(GL_POINTS);

    glVertex2i(60, 60);
    glEnd();
    glFlush();
    // glFlush();
}