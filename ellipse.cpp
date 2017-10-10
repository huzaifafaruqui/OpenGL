/*
* Draw red ellipse
*/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

#define PI 3.14

void display_ellipse() {

	//glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0.0, 0.0);

	
	for (int i = 0; i < 370; ++i) {
		glVertex2f(2.0f*cos(PI*i / 180), sin(PI*i / 180));
	}

	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);

	glVertex3f(0.0, -15, 0.0);

	glVertex3f(0.0, 15, 0.0);

	glVertex3f(-15, 0.0, 0.0);

	glVertex3f(15, 0.0, 0.0);
	glEnd();

	glFlush();

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(300, 300);   // Set the window's initial width & height
	glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
	glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
	glutDisplayFunc(display_ellipse);       // Register callback handler for window re-paint event
	//glutReshapeFunc(reshape);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.5, 2.5, -2.5, 2.5);

	//initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}