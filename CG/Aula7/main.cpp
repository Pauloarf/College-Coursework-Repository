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

/*
float camX = 0, camY = 30, camZ = 40;
int startX, startY, tracking = 0;

int alpha = 0, beta = 45, r = 50;
*/

float posX = 1, posZ = 1, posY = 0;
float lookX = 0, lookZ = 0, lookY = 5;
float alpha = 0;

float rotation = 0.1f;
float speed = 0.5f;
float accelaration = 0.01f;

float dirX = 0, dirY = 0, dirZ = 0;

float eyeHeight = 3;

std::vector<GLfloat> vertexB;
std::vector<std::vector<float>> heightMap;
GLuint buffers[1];

float baseY = posY;  // Initial ground Y-position
bool isJumping = false;
float jumpProgress = 0.0f;
float jumpHeight = 4.0f;
float jumpSpeed = 0.05f;

unsigned int t, tw, th;
unsigned char* imageData;

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

// Function to calculate the vertice heigh, in a point of the grid
float h(int x, int z) {
    int arrayX = x + (tw / 2);
    int arrayZ = z + (th / 2);

    if (arrayX >= 0 && arrayX < tw && arrayZ >= 0 && arrayZ < th) {
        return heightMap[arrayZ][arrayX];
    }
    return 0.0f;
}

// This function will return the height off a point in the grid
float hf(float x, float z) {
    // Calcular os vertices que pertencem a grid onde queremos calcular o ponto
    int x1 = floor(x);
    int x2 = x1 + 1;
    int z1 = floor(z);
    int z2 = z1 + 1;

    // Por interpolação linear calcular em z onde esta o ponto
    float fz = z - z1;
    float fx = x - x1;

    float h_x1_z = h(x1, z1) * (1 - fz) + h(x1, z2) * fz;
    float h_x2_z = h(x2, z1) * (1 - fz) + h(x2, z2) * fz;

    float height_xz = h_x1_z * (1 - fx) + h_x2_z * fx;

    return height_xz;
}

void drawTerrain() {
    int width = tw;   // Width of the height map
    int height = th;  // Height of the height map
    heightMap.resize(height, std::vector<float>(width));

    float xOffset = width / 2.0f;
    float zOffset = height / 2.0f;

    for (int z = 0; z < height - 1; z++) {
        for (int x = 0; x < width; x++) {
            vertexB.push_back((float)x - xOffset);
            vertexB.push_back(imageData[z * width + x] / 2.0f);  // Better height scaling
            vertexB.push_back((float)z - zOffset);

            heightMap[z][x] = imageData[z * width + x] / 2.0f;

            vertexB.push_back((float)x - xOffset);
            vertexB.push_back(imageData[(z + 1) * width + x] / 2.0f);
            vertexB.push_back((float)(z + 1) - zOffset);
        }
    }
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
        glTranslatef(raio * cos(angle - accelaration), 1.0f, raio * sin(angle - accelaration));
        glRotatef((-angle2 + 90) + ((accelaration * 360) / (2 * M_PI)), 0.0f, 1.0f, 0);
        glutSolidTeapot(1);
        glPopMatrix();
        angle += alpha;
        angle2 += alpha2;
    }
    glColor3f(0.2f, 0.8f, 0.2f);
}

void drawTree(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    drawCylinder(0.5, 3, 16);
    glTranslatef(0.0f, 3.0f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    glColor3f(0, 0.9f, 0);
    glutSolidCone(3, 12, 16, 4);
    glPopMatrix();
}

void drawTrees2() {
    float raio = 50;
    int count = 0;
    int nTrees = 200;
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
        float y = hf(x, z);
        drawTree(x, y, z);
        count++;
    }
}

void renderScene(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(posX, posY, posZ,
              lookX, lookY, lookZ,
              0.0f, 1.0f, 0.0f);

    glPolygonMode(GL_FRONT, GL_LINE);

    // Draw axis
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

    glEnableClientState(GL_VERTEX_ARRAY);

    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    for (int i = 0; i < (tw - 1); i++) {
        glDrawArrays(GL_TRIANGLE_STRIP, i * tw * 2, tw * 2);
    }

    glDisableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT, GL_FILL);
    accelaration += 0.01f;
    glColor3f(1.0f, 0.47f, 0.92f);
    glutSolidTorus(1, 3, 32, 64);
    glColor3f(0.2f, 0.8f, 0.2f);
    drawCloseTeaPots();
    drawFarTeaPots();
    drawTrees2();

    if (isJumping) {
        jumpProgress += jumpSpeed;
        posY = baseY + sin(jumpProgress) * jumpHeight;
        lookY = baseY + sin(jumpProgress) * jumpHeight;

        if (jumpProgress >= M_PI) {
            isJumping = false;
            posY = baseY;
        }
    }

    // End of frame
    glutSwapBuffers();
}

void applyMovement() {
    posY = eyeHeight + hf(posX, posZ);
    lookX = posX + sin(alpha);
    lookY = posY;
    lookZ = posZ + cos(alpha);
}

void cross(float dx, float dy, float dz, float fx, float fy, float fz, float& rx, float& ry, float& rz) {
    rx = dy * fz - dz * fy;
    ry = dz * fx - dx * fz;
    rz = dx * fy - dy * fx;
}

void processKeys(unsigned char key, int xx, int yy) {
    dirX = lookX - posX;
    dirZ = lookZ - posZ;

    float dirX2, dirY2, dirZ2;

    cross(dirX, dirY, dirZ, 0, 1, 0, dirX2, dirY2, dirZ2);

    switch (key) {
        case 'a':
            posX = posX - speed * dirX2;
            posY = posY - speed * dirY2;
            posZ = posZ - speed * dirZ2;
            break;
        case 'w':
            posX = posX + speed * dirX;
            posY = posY + speed * dirY;
            posZ = posZ + speed * dirZ;
            break;
        case 's':
            posX = posX - speed * dirX;
            posY = posY - speed * dirY;
            posZ = posZ - speed * dirZ;
            break;
        case 'd':
            posX = posX + speed * dirX2;
            posY = posY + speed * dirY2;
            posZ = posZ + speed * dirZ2;
            break;
        case 'j':
            alpha += rotation;
            break;
        case 'l':
            alpha -= rotation;
            break;
        case 'b':
            if (!isJumping) {
                isJumping = true;
                jumpProgress = 0.0f;
                baseY = posY;  // Store ground position
            }
            break;
        default:
            break;
    }

    applyMovement();
}

void processMouseButtons(int button, int state, int xx, int yy) {
    /*
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
    */
}

void processMouseMotion(int xx, int yy) {
    int deltaX, deltaY;
    int alphaAux, betaAux;
    int rAux;

    /*
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
    */
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
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glLineWidth(1.0f);  // Adjust thickness as needed
}

int main(int argc, char** argv) {
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
    ilInit();

    // Callback registration for keyboard processing
    glutKeyboardFunc(processKeys);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);

    glutFullScreen();

    init();

    // enter GLUT's main cycle
    glutMainLoop();

    return 0;
}
