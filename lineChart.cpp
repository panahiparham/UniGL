#include <glut.h>

GLsizei winWidth = 600, winHeight = 500;
GLint xRaster = 25, yRaster = 150;

GLubyte label [36] = { 'J', 'a', 'n',
					   'F', 'e', 'b', 
					   'M', 'a', 'r',
					   'A', 'p', 'r',
					   'M', 'a', 'y',
					   'J', 'u', 'n',
					   'J', 'u', 'l',
					   'A', 'u', 'g',
					   'S', 'e', 'p',
					   'O', 'c', 't',
					   'N', 'o', 'v',
					   'D', 'e', 'c' };

GLint dataValue [12] = { 420, 342, 324,
						 310, 262, 185,
						 190, 196, 217,
						 240, 312, 438 };

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}

void lineGraph(void)
{
	GLint x = 30;

	glClear(GL_COLOR_BUFFER_BIT);

	// draw lines
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_LINE_STRIP);

	for (int k = 0; k < 12; k++)
	{
		glVertex2i(x + k * 50, dataValue[k]);
	}

	glEnd();

	// draw * at data points
	glColor3f(1.0, 0.0, 0.0);

	for (int k = 0; k < 12; k++)
	{
		glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
	}

	// draw labels
	glColor3f(0.0, 0.0, 0.0);
	xRaster = 20;
	for (int month = 0; month < 12; month++)
	{
		glRasterPos2i(xRaster, yRaster);
		for (int k = 3 * month; k < 3 * month + 3; k++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
		}
	
		xRaster += 50;
	}
	

	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);

	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("line-chart");

	init();
	glutDisplayFunc(lineGraph);
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();

	return 0;
}