#include <GL/glut.h>
#include <stdio.h>

GLfloat vertices[8][3] = {{-1.0, -1.0, 1.0}, {-1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, -1.0, 1.0}, {-1.0, -1.0, -1.0}, {-1.0, 1.0, -1.0}, {1.0, 1.0, -1.0}, {1.0, -1.0, -1.0}};
GLfloat colors[8][3] = {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 1.0}};

void quad(int a, int b, int c, int d)
{
    glBegin(GL_QUADS);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glVertex3fv(vertices[d]);
    glEnd();
    glFlush();
}

void colorcube()
{
    quad(2, 1, 0, 3);
    quad(6, 2, 3, 7);
    quad(5, 6, 7, 4);
    quad(5, 4, 0, 1);
    quad(4, 7, 3, 0);
    quad(5, 1, 2, 6);
}
void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    // glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    colorcube();
    glFlush();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Cube Program");
    glutInitWindowPosition(250, 250);
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}