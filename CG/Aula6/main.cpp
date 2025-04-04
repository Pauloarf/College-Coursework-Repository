

#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <IL/il.h>
#include <math.h>

#include <iostream>
#include <vector>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

float camX = 0, camY = 30, camZ = 40;
int startX, startY, tracking = 0;

int alpha = 0, beta = 45, r = 200;

// Array with vertices
std::vector<GLfloat> vertexB;
GLuint buffers[1];
// 	Load the height map "terreno.jpg"
unsigned int t, tw, th;
unsigned char *imageData;

void changeSize(int w, int h) {
    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if (h == 0)
        h = 1;

    // compute window's aspect ratio
    float ratio = w * 1.0 / h;

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective
    gluPerspective(45, ratio, 1, 1000);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void drawTerrain() {
    int width = tw;   // Width of the height map
    int height = th;  // Height of the height map

    for (int z = 0; z < height - 1; z++) {
        for (int x = 0; x < width; x++) {
            // Vertex 1
            vertexB.push_back((float)x - 127);
            vertexB.push_back(imageData[z * width + x]);  // Normalize height
            vertexB.push_back((float)z - 127);

            // Vertex 2
            vertexB.push_back((float)x - 127);
            vertexB.push_back(imageData[(z + 1) * width + x]);  // Normalize height
            vertexB.push_back((float)(z + 1) - 127);
        }
    }
}

void renderScene(void) {
    float pos[4] = {-1.0, 1.0, 1.0, 0.0};

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
              0.0, 0.0, 0.0,
              0.0f, 1.0f, 0.0f);

    // just so that it renders something before the terrain is built
    // to erase when the terrain is ready
    // glutWireTeapot(2.0);

    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    for (int i = 0; i < (tw - 1); i++) {
        glDrawArrays(GL_TRIANGLE_STRIP, i * tw * 2, tw * 2);
    }

    // End of frame
    glutSwapBuffers();
}

void processKeys(unsigned char key, int xx, int yy) {
    // put code to process regular keys in here
}

void processMouseButtons(int button, int state, int xx, int yy) {
    if (state == GLUT_DOWN) {
        startX = xx;
        startY = yy;
        if (button == GLUT_LEFT_BUTTON)
            tracking = 1;
        else if (button == GLUT_RIGHT_BUTTON)
            tracking = 2;
        else
            tracking = 0;
    } else if (state == GLUT_UP) {
        if (tracking == 1) {
            alpha += (xx - startX);
            beta += (yy - startY);
        } else if (tracking == 2) {
            r -= yy - startY;
            if (r < 3)
                r = 3.0;
        }
        tracking = 0;
    }
}

void processMouseMotion(int xx, int yy) {
    int deltaX, deltaY;
    int alphaAux, betaAux;
    int rAux;

    if (!tracking)
        return;

    deltaX = xx - startX;
    deltaY = yy - startY;

    if (tracking == 1) {
        alphaAux = alpha + deltaX;
        betaAux = beta + deltaY;

        if (betaAux > 85.0)
            betaAux = 85.0;
        else if (betaAux < -85.0)
            betaAux = -85.0;

        rAux = r;
    } else if (tracking == 2) {
        alphaAux = alpha;
        betaAux = beta;
        rAux = r - deltaY;
        if (rAux < 3)
            rAux = 3;
    }
    camX = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    camZ = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    camY = rAux * sin(betaAux * 3.14 / 180.0);
}

void init() {
    ilGenImages(1, &t);
    ilBindImage(t);

    ilLoadImage((ILstring) "terreno.jpg");

    ilConvertImage(IL_LUMINANCE, IL_UNSIGNED_BYTE);

    tw = ilGetInteger(IL_IMAGE_WIDTH);
    th = ilGetInteger(IL_IMAGE_HEIGHT);

    imageData = ilGetData();

    std::cout << "Width: " << tw;
    std::cout << "Height: " << th;

    // 	Build the vertex arrays

    drawTerrain();

    glGenBuffers(1, &buffers[0]);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glBufferData(
        GL_ARRAY_BUFFER,                   // tipo do buffer, só é relevante na altura do desenho
        sizeof(GLfloat) * vertexB.size(),  // tamanho do vector em bytes
        vertexB.data(),                    // os dados do array associado ao vector
        GL_STATIC_DRAW);

    // 	OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

int main(int argc, char **argv) {
    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("CG@DI-UM");

    // Required callback registry
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glewInit();
    glEnableClientState(GL_VERTEX_ARRAY);
    ilInit();

    // Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);

    glPolygonMode(GL_FRONT, GL_LINE);

    glutFullScreen();

    init();

    // enter GLUT's main cycle
    glutMainLoop();

    return 0;
}
