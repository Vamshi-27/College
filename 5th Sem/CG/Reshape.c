#include <stdio.h>
#include <GL/glut.h>
GLfloat w = 500, h = 500;

void myinit();
void display();
void myReshape(GLsizei w, GLsizei h);
void myKey(unsigned char key, int x, int y);

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Simple OpenGL Program");
    glutInitWindowPosition(250, 250);
    glutInitWindowSize(w, h);
    glutDisplayFunc(display);
    myinit();
    glutKeyboardFunc(myKey);
    glutReshapeFunc(myReshape);
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
    glVertex2i(10, 50);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(30, 50);
    glEnd();
    glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, w, 0.0, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glViewport(0, 0, w, h);
}

void myKey(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(0);
    else if (key == 'v' || key == 'V')
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, 'V');
    glFlush();
}