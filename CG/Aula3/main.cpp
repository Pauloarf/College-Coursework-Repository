#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

#include <vector>

//----- Camera settings -----//

// Camera distance
GLfloat distance = 10.0f;

// Using distance and 45 degrees to calculate initial position
GLfloat alpha = M_PI / 4;  // Vertical angle
GLfloat beta = M_PI / 4;   // Horizontal angle

// Setting gluLookAt
GLfloat posX = distance * cos(alpha) * sin(beta);
GLfloat posY = distance * sin(alpha);
GLfloat posZ = distance * cos(alpha) * cos(beta);
GLfloat atX = 0.0f, atY = 0.0f, atZ = 0.0f;  // LookAt target
GLfloat upX = 0.0f, upY = 1.0f, upZ = 0.0f;  // Up vector

//----- end -----//

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

void torusTriangleGenerator(int majorRadius, int minorRadius, int slices, int sides) {
    GLfloat x1, y1, z1;
    GLfloat x2, y2, z2;
    GLfloat x3, y3, z3;
    GLfloat x4, y4, z4;
    GLfloat slicesJump = 2 * M_PI / slices;
    GLfloat sidesJump = 2 * M_PI / sides;
    GLfloat alpha, beta;

    // Começando por fazer a coisa pelo numero de vertices existentes na circunferencia vertical
    for (int i = 0; i < slices; i++) {
        beta = slicesJump * i;

        for (int j = 0; j < sides; j++) {
            alpha = sidesJump * j;

            x1 = (majorRadius + minorRadius * cos(alpha)) * cos(beta);
            y1 = minorRadius * sin(alpha);
            z1 = (majorRadius + minorRadius * cos(alpha)) * sin(beta);

            x2 = (majorRadius + minorRadius * cos(alpha)) * cos(beta + slicesJump);
            y2 = y1;
            z2 = (majorRadius + minorRadius * cos(alpha)) * sin(beta + slicesJump);

            x3 = (majorRadius + minorRadius * cos(alpha + sidesJump)) * cos(beta);
            y3 = minorRadius * sin(alpha + sidesJump);
            z3 = (majorRadius + minorRadius * cos(alpha + sidesJump)) * sin(beta);

            x4 = (majorRadius + minorRadius * cos(alpha + sidesJump)) * cos(beta + slicesJump);
            y4 = y3;
            z4 = (majorRadius + minorRadius * cos(alpha + sidesJump)) * sin(beta + slicesJump);

            // Desenar faces
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.8f, 0.0f);
            glVertex3f(x3, y3, z3);
            glVertex3f(x2, y2, z2);
            glVertex3f(x1, y1, z1);
            glEnd();
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.5f, 0.0f);
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);
            glVertex3f(x2, y2, z2);
            glEnd();
        }
    }
}

void diskTriangleGenerator(int majorRadius, int minorRadius, int slices) {
    GLfloat x1, y1, z1;
    GLfloat x2, y2, z2;
    GLfloat x3, y3, z3;
    GLfloat x4, y4, z4;
    GLfloat slicesJump = 2 * M_PI / slices;
    GLfloat beta;

    // Começando por fazer a coisa pelo numero de vertices existentes na circunferencia vertical
    for (int i = 0; i < slices; i++) {
        beta = slicesJump * i;

        x1 = (majorRadius + minorRadius) * cos(beta);
        y1 = 0.0f;
        z1 = (majorRadius + minorRadius) * sin(beta);

        x2 = (majorRadius + minorRadius) * cos(beta + slicesJump);
        y2 = 0.0f;
        z2 = (majorRadius + minorRadius) * sin(beta + slicesJump);

        x3 = (majorRadius - minorRadius) * cos(beta);
        y3 = 0.0f;
        z3 = (majorRadius - minorRadius) * sin(beta);

        x4 = (majorRadius - minorRadius) * cos(beta + slicesJump);
        y4 = 0.0f;
        z4 = (majorRadius - minorRadius) * sin(beta + slicesJump);

        // Desenar faces
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.8f, 0.0f);
        // UP
        glVertex3f(x3, y3, z3);
        glVertex3f(x2, y2, z2);
        glVertex3f(x1, y1, z1);
        // DOWN
        glVertex3f(x2, y2, z2);
        glVertex3f(x4, y4, z4);
        glVertex3f(x3, y3, z3);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.5f, 0.0f);
        // UP
        glVertex3f(x3, y3, z3);
        glVertex3f(x4, y4, z4);
        glVertex3f(x2, y2, z2);
        // DOWN
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x3, y3, z3);
        glEnd();
    }
}

struct Vertex {
    float x, y, z;
};

std::vector<Vertex> vertices;
std::vector<unsigned int> indices;

void addVertex(float x, float y, float z) {
    vertices.push_back({x, y, z});
}

void addFace(int a, int b, int c) {
    indices.push_back(a);
    indices.push_back(b);
    indices.push_back(c);
}

void createIcosahedron() {
    const float t = (1.0f + sqrt(5.0f)) / 2.0f;

    addVertex(-1, t, 0);
    addVertex(1, t, 0);
    addVertex(-1, -t, 0);
    addVertex(1, -t, 0);

    addVertex(0, -1, t);
    addVertex(0, 1, t);
    addVertex(0, -1, -t);
    addVertex(0, 1, -t);

    addVertex(t, 0, -1);
    addVertex(t, 0, 1);
    addVertex(-t, 0, -1);
    addVertex(-t, 0, 1);

    addFace(0, 11, 5);
    addFace(0, 5, 1);
    addFace(0, 1, 7);
    addFace(0, 7, 10);
    addFace(0, 10, 11);

    addFace(1, 5, 9);
    addFace(5, 11, 4);
    addFace(11, 10, 2);
    addFace(10, 7, 6);
    addFace(7, 1, 8);

    addFace(3, 9, 4);
    addFace(3, 4, 2);
    addFace(3, 2, 6);
    addFace(3, 6, 8);
    addFace(3, 8, 9);

    addFace(4, 9, 5);
    addFace(2, 4, 11);
    addFace(6, 2, 10);
    addFace(8, 6, 7);
    addFace(9, 8, 1);
}

void subdivide() {
    std::vector<unsigned int> newIndices;
    std::vector<Vertex> newVertices = vertices;

    for (size_t i = 0; i < indices.size(); i += 3) {
        int a = indices[i];
        int b = indices[i + 1];
        int c = indices[i + 2];

        Vertex v1 = vertices[a];
        Vertex v2 = vertices[b];
        Vertex v3 = vertices[c];

        Vertex v4 = {(v1.x + v2.x) / 2, (v1.y + v2.y) / 2, (v1.z + v2.z) / 2};
        Vertex v5 = {(v2.x + v3.x) / 2, (v2.y + v3.y) / 2, (v2.z + v3.z) / 2};
        Vertex v6 = {(v1.x + v3.x) / 2, (v1.y + v3.y) / 2, (v1.z + v3.z) / 2};

        int i4 = newVertices.size();
        newVertices.push_back(v4);
        int i5 = newVertices.size();
        newVertices.push_back(v5);
        int i6 = newVertices.size();
        newVertices.push_back(v6);

        newIndices.push_back(a);
        newIndices.push_back(i4);
        newIndices.push_back(i6);
        newIndices.push_back(i4);
        newIndices.push_back(b);
        newIndices.push_back(i5);
        newIndices.push_back(i6);
        newIndices.push_back(i5);
        newIndices.push_back(c);
        newIndices.push_back(i4);
        newIndices.push_back(i5);
        newIndices.push_back(i6);
    }

    vertices = newVertices;
    indices = newIndices;
}

void normalize() {
    for (auto& v : vertices) {
        float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        v.x /= length;
        v.y /= length;
        v.z /= length;
    }
}

void renderIcosphere() {
    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < indices.size(); i++) {
        Vertex v = vertices[indices[i]];
        if (i % 2 == 0) {
            glColor3f(0.0f, 0.8f, 0.0f);
        } else {
            glColor3f(0.0f, 0.5f, 0.0f);
        }
        glVertex3f(v.x, v.y, v.z);
    }
    glEnd();
}

void renderScene(void) {
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(
        posX, posY, posZ,
        atX, atY, atZ,
        upX, upY, upZ);

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

    // Changes color back to white
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();

    // drawCylinder(4, 6, 20);
    // torusTriangleGenerator(4, 2, 72, 36);
    // diskTriangleGenerator(10, 2, 36);
    renderIcosphere();

    // End of frame
    glutSwapBuffers();
}

// Function to update camera position using spherical coordinates
void updateCameraPosition() {
    posX = distance * cos(alpha) * sin(beta);
    posY = distance * sin(alpha);
    posZ = distance * cos(alpha) * cos(beta);
}

void processKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':  // Tilt up
            if (alpha < M_PI / 2 - 0.05f) alpha += 0.05f;
            break;
        case 's':  // Tilt down
            if (alpha > -M_PI / 2 + 0.05f) alpha -= 0.05f;
            break;
        case 'a':  // Rotate left
            beta -= 0.05f;
            break;
        case 'd':  // Rotate right
            beta += 0.05f;
            break;
        case 'h':  // Solid mode
            glPolygonMode(GL_FRONT, GL_FILL);
            break;
        case 'j':  // Wireframe mode
            glPolygonMode(GL_FRONT, GL_LINE);
            break;
        case 'k':  // Point mode
            glPolygonMode(GL_FRONT, GL_POINT);
            break;
        default:
            break;
    }
    updateCameraPosition();
    glutPostRedisplay();
}

void processSpecialKeys(int key, int xx, int yy) {
    // put code to process special keys in here
}

int main(int argc, char** argv) {
    // init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM");

    createIcosahedron();
    for (int i = 0; i < 3; ++i) {
        subdivide();
        normalize();
    }

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
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // enter GLUT's main cycle
    glutMainLoop();

    return 1;
}
