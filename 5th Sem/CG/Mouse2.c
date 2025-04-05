#include<stdio.h>
#include<GL/glut.h>

void myinit();
void display();
void myMouse(int button,int state,int x,int y);

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Simple OpenGL Program");
	glutInitWindowPosition(250,250);
	glutInitWindowSize(500,500);
	glutDisplayFunc(display);
	myinit();
	glutMouseFunc(myMouse);
	glutMainLoop();
}

void myinit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0.0,100.0,0.0,100.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
        glColor3f(1.0,0.0,0.0);
        glVertex2i(10,60);
        glColor3f(0.0,1.0,0.0);
        glVertex2i(15,75);
	glEnd();
	glFlush();
}

void myMouse(int button,int state,int x,int y)
{
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'V');
	}
	else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		exit(0);
	glFlush();
}