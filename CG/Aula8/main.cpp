#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float camX = 0, camY, camZ = 10;
int startX, startY, tracking = 0;

int alpha = 0, beta = 0, r = 10;

#define POINT_COUNT 7
// Points that make up the loop for catmull-rom interpolation
float p[POINT_COUNT][3] = {{-1, -1, 0}, {-1, 1, 0}, {-2, 3, 0}, {1, 1, 0}, {0, 0, 0}, {1, -1, 0}, {1, -3, 0}};

void buildRotMatrix(float *x, float *y, float *z, float *m) {
    m[0] = x[0];
    m[1] = x[1];
    m[2] = x[2];
    m[3] = 0;
    m[4] = y[0];
    m[5] = y[1];
    m[6] = y[2];
    m[7] = 0;
    m[8] = z[0];
    m[9] = z[1];
    m[10] = z[2];
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 1;
}

void cross(float *a, float *b, float *res) {
    res[0] = a[1] * b[2] - a[2] * b[1];
    res[1] = a[2] * b[0] - a[0] * b[2];
    res[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(float *a) {
    float l = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0] / l;
    a[1] = a[1] / l;
    a[2] = a[2] / l;
}

float length(float *v) {
    float res = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    return res;
}

void multMatrixVector(float *m, float *v, float *res) {
    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }
}

void getCatmullRomPoint(float t, float *p0, float *p1, float *p2, float *p3, float *pos, float *deriv) {
    // catmull-rom matrix
    float m[4][4] = {{-0.5f, 1.5f, -1.5f, 0.5f},
                     {1.0f, -2.5f, 2.0f, -0.5f},
                     {-0.5f, 0.0f, 0.5f, 0.0f},
                     {0.0f, 1.0f, 0.0f, 0.0f}};

    // Compute A = M * P for all x,y and z component
    for (int i = 0; i < 3; i++) {
        float v[4] = {p0[i], p1[i], p2[i], p3[i]};
        float A[4] = {0.f, 0.0f, 0.0f, 0.0f};
        multMatrixVector(&m[0][0], v, A);

        pos[i] = A[0] * pow(t, 3) + A[1] * pow(t, 2) + A[2] * t + A[3];
        deriv[i] = 3 * A[0] * pow(t, 2) + 2 * A[1] * t + A[2];
    }
}

// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv) {
    float t = gt * POINT_COUNT;  // this is the real global t
    int index = floor(t);        // which segment
    t = t - index;               // where within  the segment

    // indices store the points
    int indices[4];
    indices[0] = (index + POINT_COUNT - 1) % POINT_COUNT;
    indices[1] = (indices[0] + 1) % POINT_COUNT;
    indices[2] = (indices[1] + 1) % POINT_COUNT;
    indices[3] = (indices[2] + 1) % POINT_COUNT;

    getCatmullRomPoint(t, p[indices[0]], p[indices[1]], p[indices[2]], p[indices[3]], pos, deriv);
}

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

void renderCatmullRomCurve() {
    /*

        float k[4][3] = {{0.0f, 0.0f, 0.0f},
    {1.1f, 0.0f, 1.1f},
    {-1.0f, 0.0f, 1.0f},
    {-1.0f, 0.0f, 0.0f}};
    */

    float pos[3];
    float deriv[3];

    glBegin(GL_LINE_LOOP);
    for (float i = 0.01f; i < 1.0f; i += 0.01f) {
        getGlobalCatmullRomPoint(i, pos, deriv);
        glVertex3f(pos[0], pos[1], pos[2]);
    }
    glEnd();
}

void renderScene(void) {
    static float t = 0;

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
              0.0, 0.0, 0.0,
              0.0f, 1.0f, 0.0f);

    renderCatmullRomCurve();

    // apply transformations here
    // Declarar a posição e o vetor deriv
    float pos[3];
    float deriv[3];

    getGlobalCatmullRomPoint(t, pos, deriv);

    // Normalizar o vetor tangente
    normalize(deriv);

    // Declarar o up temporario
    float up[3] = {0.0f, 1.0f, 0.0f};
    if (deriv[0] < 0) {
        up[1] = -1.0f;
    }

    // Declarar o vetor Z
    float zAxis[3];

    // Calcular e normalizar o vetor z
    cross(deriv, up, zAxis);
    normalize(zAxis);

    // Obter o vetor up
    // Normalizar o vetor up
    float newUp[3];
    cross(zAxis, deriv, newUp);
    normalize(newUp);

    glBegin(GL_LINES);
    // x in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(pos[0], pos[1], pos[2]);
    glVertex3f(pos[0] + deriv[0], pos[1] + deriv[1], pos[2] + deriv[2]);

    // z in blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(pos[0], pos[1], pos[2]);
    glVertex3f(pos[0] + zAxis[0], pos[1] + zAxis[1], pos[2] + zAxis[2]);
    // y in green
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(pos[0], pos[1], pos[2]);
    glVertex3f(pos[0] + newUp[0], pos[1] + newUp[1], pos[2] + newUp[2]);
    // Changes color back to white
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();

    float rot[4][4];
    // Build the rotation matrix
    buildRotMatrix(deriv, newUp, zAxis, &rot[0][0]);

    // Aplicar primeiro a translação e depois a rotação
    glTranslatef(pos[0], pos[1], pos[2]);
    glMultMatrixf(&rot[0][0]);

    glutWireTeapot(0.5);

    glutSwapBuffers();
    // t += 0.00001;
    t += 0.001;
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

void processKeys(unsigned char key, int mx, int my) {
    switch (key) {
        case '+':
            r--;
            break;
        case '-':
            r++;
            break;
        default:
            break;
    }
}

int main(int argc, char **argv) {
    // inicialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("CG@DI-UM");

    // callback registration
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);

    // mouse callbacks
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);
    glutKeyboardFunc(processKeys);

    // OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
