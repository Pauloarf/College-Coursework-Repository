#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

GLfloat rotate = 0;
GLfloat scale = 1;
GLfloat transy = 0;
GLfloat transz = 0;

GLfloat rotateXZ = 0.0f;
// Camara Settings
GLfloat camaraX = 15.0f;
GLfloat camaraY = 15.0f;
GLfloat camaraZ = 15.0f;

GLfloat camaraAtx = 0.0f;
GLfloat camaraAty = 0.0f;
GLfloat camaraAtz = 0.0f;

GLfloat camaraUp = 1;

void changeSize(int w, int h) {
    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
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
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void drawCylinder(float radius, float height, int slices) {
    float alpha = (2 * M_PI) / slices;

    for (int i = 0; i < slices; i++) {
        // Bottom-left
        float x1 = radius * cos(i * alpha);
        float z1 = radius * sin(i * alpha);

        float x2 = radius * cos((i + 1) * alpha);
        float z2 = radius * sin((i + 1) * alpha);

        // Definir a cor dos triangulos
        if (i % 2 == 0) {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 0.7f);
            glEnd();
        } else {
            glBegin(GL_TRIANGLES);
            glColor3f(0.7f, 0.0f, 0.0f);
            glEnd();
        }

        // Desenhar triangulos base
        glBegin(GL_TRIANGLES);
        glVertex3f(x2, 0.0f, z2);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x1, 0.0f, z1);
        glEnd();

        // Desenhar triangulos topo
        glBegin(GL_TRIANGLES);
        glVertex3f(x1, height, z1);
        glVertex3f(0.0f, height, 0.0f);
        glVertex3f(x2, height, z2);
        glEnd();

        // Desenar faces
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.8f, 0.0f);
        glVertex3f(x1, 0.0f, z1);
        glVertex3f(x1, height, z1);
        glVertex3f(x2, 0.0f, z2);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.5f, 0.0f);
        glVertex3f(x1, height, z1);
        glVertex3f(x2, height, z2);
        glVertex3f(x2, 0.0f, z2);
        glEnd();
    }
}

void coneTriangleGenerator(int radius, int height, int slices, int stacks) {
    float alpha = (2 * M_PI) / slices;
    float stackHeight = static_cast<float>(height) / stacks;
    int nTriangles = 0;

    for (int i = 0; i < slices; i++) {
        float x1 = radius * cos(i * alpha);
        float z1 = radius * sin(i * alpha);
        float x2 = radius * cos((i + 1) * alpha);
        float z2 = radius * sin((i + 1) * alpha);

        glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(x1, 0.0f, z1);
        glVertex3f(x2, 0.0f, z2);
        glEnd();
    }

    for (int i = 0; i < slices; i++) {
        for (int j = 0; j < stacks; j++) {
            float y1 = j * stackHeight;
            float y2 = (j + 1) * stackHeight;

            float x1 = radius * cos(i * alpha) * (1 - (float)(j + 1) / stacks);
            float z1 = radius * sin(i * alpha) * (1 - (float)(j + 1) / stacks);
            float x2 = radius * cos((i + 1) * alpha) * (1 - (float)(j + 1) / stacks);
            float z2 = radius * sin((i + 1) * alpha) * (1 - (float)(j + 1) / stacks);

            float x3 = radius * cos(i * alpha) * (1 - (float)j / stacks);
            float z3 = radius * sin(i * alpha) * (1 - (float)j / stacks);
            float x4 = radius * cos((i + 1) * alpha) * (1 - (float)j / stacks);
            float z4 = radius * sin((i + 1) * alpha) * (1 - (float)j / stacks);

            // Definir a cor dos triangulos
            if (i % 2 == 0) {
                glBegin(GL_TRIANGLES);
                glColor3f(0.0f, 0.0f, 0.7f);
                glEnd();
            } else {
                glBegin(GL_TRIANGLES);
                glColor3f(0.7f, 0.0f, 0.0f);
                glEnd();
            }

            glBegin(GL_TRIANGLES);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y1, z3);
            glVertex3f(x1, y2, z1);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(x2, y2, z2);
            glVertex3f(x4, y1, z4);
            glVertex3f(x3, y1, z3);
            glEnd();
        }
    }
}

void renderScene(void) {
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

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera

    glLoadIdentity();
    gluLookAt(camaraX, camaraY, camaraZ,
              camaraAtx, camaraAty, camaraAtz,
              0.0f, camaraUp, 0.0f);

    // drawCylinder(1, 2, 10);
    coneTriangleGenerator(6, 8, 8, 4);

    // End of frame
    glutSwapBuffers();
}

void processKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 'e':
            rotate += 0.5;
            break;
        case 'q':
            rotate -= 0.5;
            break;
        case 'b':
            scale += 0.1f;
            break;
        case 'l':
            scale -= 0.1f;
            break;
        case 'w':
            transy -= 0.1f;
            break;
        case 's':
            transy += 0.1f;
            break;
        case 'a':
            rotateXZ -= 0.01f;
            camaraX = camaraX * cos(rotateXZ);
            camaraZ = camaraZ * sin(rotateXZ);
            break;
        case 'd':
            rotateXZ += 0.01f;
            camaraX = (camaraX * cos(rotateXZ));
            camaraZ = (camaraZ * sin(rotateXZ));
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

void processSpecialKeys(int key, int xx, int yy) {
    // put code to process special keys in here
}

int main(int argc, char **argv) {
    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM");

    // Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    // glutIdleFunc(renderScene);

    // Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    // glutSpecialFunc(processSpecialKeys);

    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
