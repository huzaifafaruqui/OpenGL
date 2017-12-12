#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>
#include <vector>

using namespace std;

int windowWidth = 320, windowHeight = 240;
int windowPosX = 50, windowPosY = 50;
int k;

struct Point {
	int x, y;
	Point(int x1, int y1) : x(x1), y(y1) {}
	Point() : x(0), y(0) {}
} curr;

vector<Point> points;

void display() {

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < points.size(); ++i) {
		glVertex2i(points[i].x, points[i].y);
	}
	glEnd();

	glFlush();
}


void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	//glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key, int x, int y) {

	if (key == 27) {
		exit(0);
	}
}


void mouse(int button, int state, int x, int y) {
	int yy = glutGet(GLUT_WINDOW_HEIGHT);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		k = 1;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		k = 0;
		points.clear();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		glClear(GL_COLOR_BUFFER_BIT);
	}

}


void moveMouse(int x, int y) {
	if (k) {
		int yy = glutGet(GLUT_WINDOW_HEIGHT);
		points.push_back(Point(x, yy - y));
		glutPostRedisplay();
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(windowPosX, windowPosY);
	glutCreateWindow("Draw lines using mouse");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(moveMouse);
	//glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();
	return 0;
}
