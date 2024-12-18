#include <GL/glut.h>
#include <stdio.h>

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    glPointSize(6.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);

    glVertex2i(10, 10);
    glVertex2i(10, 90);
    glEnd();
    glFlush();
}
void display1()
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
}
void demo_menu(int id)
{
    switch (id)
    {
    case 1:
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, '@');
        break;
    case 2:
        glRasterPos2f(10.0, 50.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'c');
        break;
    case 3:
        display1();
        break;
    case 4:
        exit(0);
        break;
    }
    glFlush();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("simple openGL pgm");
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    myinit();
    glutCreateMenu(demo_menu);
    glutAddMenuEntry("glut storke", 1);
    glutAddMenuEntry("bitmap", 2);
    glutAddMenuEntry("display", 3);
    glutAddMenuEntry("exit", 4);
    glutDisplayFunc(display);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}