#include <GL/glut.h>
#include <iostream>

using namespace std;

double x1,x2,y1,y2;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,1);
	glLoadIdentity();
	double m=(y2-y1)/(x2-x1);
	glBegin(GL_POINTS);
	double x,y;
	for (x=x1; x<=x2; x+=0.000001)
	{
		y=(y1+m*(x-x1));
		glVertex3f(x,y,0.0f);
	}
	glEnd();
	glFlush();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void init()
{
	glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	cout<<"Ingrese los puntos"<<endl;
	cout<<"X1:"<<endl;
	cin>>x1;
	cout<<"Y1:"<<endl;
	cin>>y1;
	cout<<"X2:"<<endl;
	cin>>x2;
	cout<<"Y2:"<<endl;
	cin>>y2;
	x1/=100; x2/=100; y1/=100; y2/=100;
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Linea Incremental Basico");
	init();
	glutDisplayFunc (display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

