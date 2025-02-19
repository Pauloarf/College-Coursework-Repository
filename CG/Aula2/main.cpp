#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

int rotate = 0;
GLfloat scale = 1;
GLfloat transx = 0;
GLfloat transy = 0;
GLfloat transz = 0;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(0.0,5.0,5.0, 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	// put axis drawing in here
	glBegin(GL_LINES);
	// x in red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-100.f, 0.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	// y in green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -100.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	// z in blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.f, 0.0f, -100.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();

	// put the geometric transformations here
	glTranslatef(transx, transy, transz);
	glScalef(scale, scale, scale);
	glRotatef(rotate, 0, 1, 0);

	// put pyramid drawing instructions here
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.9f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.8f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.7f);
	glVertex3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.6f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, -1.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glEnd();

	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events

void pressKey(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'e':
		rotate += 1;
		break;
	case 'q':
		rotate -= 1;
		break;
	case 'b':
		scale += 0.1f;
		break;
	case 'l':
		scale -= 0.1f;
		break;
	case 'w':
		transz -= 0.1f;
		break;
	case 's':
		transz += 0.1f;
		break;
	case 'a':
		transx -= 0.1f;
		break;
	case 'd':
		transx += 0.1f;
		break;
	case 'h':
		glPolygonMode(GL_FRONT, GL_FILL);
		break;
	case 'j':
		glPolygonMode(GL_FRONT, GL_LINE);
		break;
	case 'k':
		glPolygonMode(GL_FRONT, GL_POINT);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}




int main(int argc, char **argv) {

	// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
	// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	
	// put here the registration of the keyboard callbacks
	glutKeyboardFunc(pressKey);

	//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
	// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
