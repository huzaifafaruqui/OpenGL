// Source http://www3.ntu.edu.sg/home/ehchua/programming/opengl/cg_introduction.html

#include <windows.h>
#include <GL/glut.h>
#include <math.h>     // Needed for sin, cos
#define PI 3.14159265f

using namespace std;

// Global variables
char title[] = "Zoom Circle";  // Windowed mode's title
int windowWidth = 640 ;     // Windowed mode's width
int windowHeight = 480 ;     // Windowed mode's height
int windowPosX = 50;      // Windowed mode's top-left corner x
int windowPosY = 50;      // Windowed mode's top-left corner y

GLfloat ballRadius = 0.2f;   // Radius of the ball
int refreshMillis = 30;      // Refresh period in milliseconds
GLfloat zoomFactor = 1.0;

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // Set background (clear) color to black
}

/* Callback handler for window re-paint event */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
								   
	glMatrixMode(GL_MODELVIEW);    // To operate on the model-view matrix
	glLoadIdentity();              // Reset model-view matrix
	glScalef(zoomFactor, zoomFactor, 0.0f);  // http://www.coders-hub.com/2013/06/opengl-code-to-zoom-in-and-zoom-out.html#.We9c6jyXdPY						   
	// Use triangular segments to form a circle
	glBegin(GL_TRIANGLE_FAN); 
	glColor3f(0.0f, 0.0f, 1.0f);  // Blue
	glVertex2f(0.0f, 0.0f);       // Center of circle
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
		angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
		glVertex2f(cos(angle) * ballRadius, sin(angle) * ballRadius);
	}
	glEnd();

	glutSwapBuffers();  // Swap front and back buffers (of double buffered mode)
}


void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:     // ESC key
		exit(0);
		break;
	}
}

/* Callback handler for special-key event */
void specialKeys(int key, int x, int y) {
	switch (key) {

	case GLUT_KEY_UP:    // Zoom in
		zoomFactor += 0.10;
		if (zoomFactor > 4.0)
			zoomFactor = 4.0;
		break;
	case GLUT_KEY_DOWN:     // Zoom out
		zoomFactor -= 0.10;
		if (zoomFactor < 0.1)
			zoomFactor = 0.1;
		break;

	}
}

/* Called back when the timer expired */
void Timer(int value) {
	glutPostRedisplay();    // Post a paint request to activate display()
	glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(windowWidth, windowHeight);  // Initial window width and height
	glutInitWindowPosition(windowPosX, windowPosY); // Initial window top-left corner (x, y)
	glutCreateWindow(title);      // Create window with given title
	glutDisplayFunc(display);     // Register callback handler for window re-paint
	glutTimerFunc(0, Timer, 0);   // First timer call immediately
	glutSpecialFunc(specialKeys); // Register callback handler for special-key event
	glutKeyboardFunc(keyboard);   // Register callback handler for special-key event
	initGL();                     // Our own OpenGL initialization
	glutMainLoop();               // Enter event-processing loop
	return 0;
}
