#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

float alfa = 0.0f, beta = 0.5f, radius = 100.0f;
float camX, camY, camZ;

void spherical2Cartesian() {
    camX = radius * cos(beta) * sin(alfa);
    camY = radius * sin(beta);
    camZ = radius * cos(beta) * cos(alfa);
}

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

void drawCloseTeaPots() {
    float raio = 15;
    float nDraws = 8;
    float alpha = (2 * M_PI) / 8;
    float alpha2 = 360 / 8;
    glColor3f(0.0f, 0.0f, 0.9f);

    float angle = 0.0f;
    float angle2 = 0.0f;
    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        glTranslatef(raio * cos(angle), 1.0f, raio * sin(angle));
        glRotatef(-angle2, 0.0f, 1.0f, 0);
        glutSolidTeapot(1);
        glPopMatrix();
        angle += alpha;
        angle2 += alpha2;
    }
    glColor3f(0.2f, 0.8f, 0.2f);
}

float speed = 0.001f;

void drawFarTeaPots() {
    float raio = 35;
    float nDraws = 16;
    float alpha = (2 * M_PI) / 16;
    float alpha2 = 360 / 16;
    glColor3f(1.0f, 0.0f, 0.0f);

    float angle = 0.0f;
    float angle2 = 0.0f;
    for (int i = 0; i < 16; i++) {
        glPushMatrix();
        glTranslatef(raio * cos(angle - speed), 1.0f, raio * sin(angle - speed));
        glRotatef((-angle2 + 90) + ((speed * 360) / (2 * M_PI)), 0.0f, 1.0f, 0);
        glutSolidTeapot(1);
        glPopMatrix();
        angle += alpha;
        angle2 += alpha2;
    }
    glColor3f(0.2f, 0.8f, 0.2f);
}

void drawCylinder(float radius, float height, int slices) {
    float alpha = (2 * M_PI) / slices;

    for (int i = 0; i < slices; i++) {
        // Bottom-left
        float x1 = radius * cos(i * alpha);
        float z1 = radius * sin(i * alpha);

        float x2 = radius * cos((i + 1) * alpha);
        float z2 = radius * sin((i + 1) * alpha);

        glColor3f(0.5f, 0.37f, 0.17f);
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
        glVertex3f(x1, 0.0f, z1);
        glVertex3f(x1, height, z1);
        glVertex3f(x2, 0.0f, z2);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3f(x1, height, z1);
        glVertex3f(x2, height, z2);
        glVertex3f(x2, 0.0f, z2);
        glEnd();
    }
}

void drawTree(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    drawCylinder(0.5, 3, 16);
    glTranslatef(0.0f, 3.0f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    glColor3f(0, 0.9f, 0);
    glutSolidCone(3, 12, 16, 4);
    glPopMatrix();
}

void drawTrees() {
    float raio = 50 * 50;
    int count = 0;
    int nTrees = 100;
    srand(1);
    while (count < nTrees) {
        float x = rand() * 100 / RAND_MAX;
        float z = rand() * 100 / RAND_MAX;
        if ((x * x + z * z) > raio) {
            glPushMatrix();
            glTranslatef(x, 0.0f, z);
            drawTree(x, z);
            glPopMatrix();
            count++;
        }
    }
}

void drawTrees2() {
    float raio = 50;
    int count = 0;
    int nTrees = 150;
    srand(1);
    while (count < nTrees) {
        int x = rand() % 100;
        int z = rand() % 100;
        if (pow(x, 2) + pow(z, 2) < pow(50, 2)) {
            continue;
        }
        if (z % 2 == 0) {
            z = -z;
        }
        if (x % 2 == 0) {
            x = -x;
        }
        // std::cout << x;
        drawTree(x, z);
        count++;
    }
}

void renderScene(void) {
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
              0.0, 0.0, 0.0,
              0.0f, 1.0f, 0.0f);

    // put axis drawing in here
    glBegin(GL_LINES);
    // x in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-100.f, 0.0f, 0.0f);
    glVertex3f(200.0f, 0.0f, 0.0f);
    // y in green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    // z in blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.f, 0.0f, -100.0f);
    glVertex3f(0.0f, 0.0f, 200.0f);

    // Changes color back to white
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();

    glColor3f(0.2f, 0.8f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex3f(100.0f, 0, -100.0f);
    glVertex3f(-100.0f, 0, -100.0f);
    glVertex3f(-100.0f, 0, 100.0f);

    glVertex3f(100.0f, 0, -100.0f);
    glVertex3f(-100.0f, 0, 100.0f);
    glVertex3f(100.0f, 0, 100.0f);
    glEnd();

    // put code to draw scene in here
    speed += 0.001f;
    glColor3f(1.0f, 0.47f, 0.92f);
    glutSolidTorus(1, 3, 32, 64);
    glColor3f(0.2f, 0.8f, 0.2f);

    drawCloseTeaPots();
    drawFarTeaPots();
    drawTrees2();
    // drawTree();

    glutSwapBuffers();
}

void processKeys(unsigned char c, int xx, int yy) {
    // put code to process regular keys in here
}

void processSpecialKeys(int key, int xx, int yy) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            alfa -= 0.1;
            break;

        case GLUT_KEY_LEFT:
            alfa += 0.1;
            break;

        case GLUT_KEY_UP:
            beta += 0.1f;
            if (beta > 1.5f)
                beta = 1.5f;
            break;

        case GLUT_KEY_DOWN:
            beta -= 0.1f;
            if (beta < -1.5f)
                beta = -1.5f;
            break;

        case GLUT_KEY_PAGE_DOWN:
            radius -= 1.0f;
            if (radius < 1.0f)
                radius = 1.0f;
            break;

        case GLUT_KEY_PAGE_UP:
            radius += 1.0f;
            break;
    }
    spherical2Cartesian();
    glutPostRedisplay();
}

void printInfo() {
    printf("Vendor: %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version: %s\n", glGetString(GL_VERSION));

    printf("\nUse Arrows to move the camera up/down and left/right\n");
    printf("Home and End control the distance from the camera to the origin");
}

int main(int argc, char **argv) {
    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("CG@DI-UM");

    // Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    // Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(processSpecialKeys);

    //  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    spherical2Cartesian();

    printInfo();

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
