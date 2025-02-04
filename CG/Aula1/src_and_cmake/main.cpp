#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

double value = 0;
bool grow = false;
float rotationValue = 0;

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you can�t make a window with zero width).
	if (h == 0)
		h = 1;
	// compute window's aspect ratio
	float ratio = w * 1.0f / h;
	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load the identity matrix
	glLoadIdentity();
	// Set the perspective
	gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);

	// finally set the viewport to be the entire window
	glViewport(0, 0, w, h);
}


void renderScene(void)
{
	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// set camera
	glLoadIdentity();

	rotationValue = rotationValue + 0.01;

	gluLookAt(0.0f, 0.0f, 5.0f,
		cos(rotationValue), sin(rotationValue), -1.0f,
		0.0f, 1.0f, 0.0f);
		
	// put drawing instructions here
	if (!grow) {
		value = value + 0.01;
	}
	else {
		value = value - 0.01;
	}
	if (value > (M_PI / 2)) {
		grow = true;
	}
	if (grow && value <= 0) {
		grow = false;
	}
	glutWireTeapot(1);
	
	// End of frame
	glutSwapBuffers();
}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
}


int main(int argc, char** argv)
{
	// put GLUT init here
	// Esta função inicia o glut e é obrigatória
	glutInit(&argc, argv);
	// Define um conjunto de medidas para a janela
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	// Define a posição da camara em pixeis, posição do canto superior esquerdo
	glutInitWindowPosition(100, 100);
	// Define altura e largura da janela
	glutInitWindowSize(800, 800);
	// Cria a janela, a sting usada como parametro define o nome da janela (caption)
	glutCreateWindow("CG@DI");
    
	// put callback registry here
	// Esta função é chamada quando a janela aparece e quando o seu tamanho é alterado
	glutReshapeFunc(changeSize);
	// Quando a event queue fica vazia esta função é chamada
	glutIdleFunc(renderScene);
	// A callback function (evento) responsavel por voltar a redesenhar o conteudo da janela
	glutDisplayFunc(renderScene);

	// some OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// enter GLUT’s main cycle
	glutMainLoop();
	
	return 1;
}