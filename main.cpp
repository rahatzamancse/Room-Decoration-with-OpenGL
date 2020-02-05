#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif // STB_IMAGE_IMPLEMENTATION

#include "Player.h"
#include "Camera.h"
#include "Room.h"
#include "Jack.h"
#include "Table.h"
#include "TexturedCube.h"
#include "RoomTextured.h"
#include "TableTextured.h"

#define PI 3.1415926535897932384626433832795

static int WINDOW_WIDTH = 1280, WINDOW_HEIGHT = 480;

Camera cam(WINDOW_WIDTH/2, WINDOW_HEIGHT, Vector(0, 4, -5), Vector(0, 0, 0)-Vector(0, 0, -5), Vector(0, 1, 0));
Player* player;
Room* room;
Jack* jack;
Table* table;
TexturedCube* texbox;
RoomTextured* texRoom;
TableTextured* texTable;

static void resize(int width, int height)
{
    WINDOW_HEIGHT = height;
    WINDOW_WIDTH = width;
    cam.update_ratio(WINDOW_WIDTH/2, WINDOW_HEIGHT);
    const float ar = (float) width/2 / (float) height;

    glViewport(0, 0, width/2, height);
    cam.update();

    glViewport(width/2+1, 0, width/2, height);
    cam.update();

    glFrustum(-ar, ar, -1.0, 1.0, 0.01, 300.0);
}

static bool light0_state = true;
const GLfloat light0_ambient[]  = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat light0_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light0_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light0_position[] = { 2.0f, 5.0f, 3.0f, 0.0f };

static bool light1_state = true;
const GLfloat light1_ambient[]  = { 0.1f, 0.1f, 0.1f, 1.0f };
const GLfloat light1_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light1_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
Vector light1_position(-3.0f, 5.0f, 0.0f);
Vector light1_direction = Vector(-3, 2, 3) - light1_position;
GLfloat light1_pos[] = { light1_position.getX(), light1_position.getY(), light1_position.getZ(), 1.0f };
GLfloat spot_dir[] = { light1_direction.getX(), light1_direction.getY(), light1_direction.getZ()};


double sc = 1;
static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glViewport(0, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT);

    cam.update();

    glScaled(sc, sc, sc);

    if(light0_state) {
        glEnable(GL_LIGHT0);
        glPushMatrix();
            glTranslated(light0_position[0], light0_position[1], light0_position[2]);
            glutWireSphere(0.5, 32, 32);
        glPopMatrix();
    }
    else glDisable(GL_LIGHT0);
    if(light1_state) {
        glEnable(GL_LIGHT1);
        glPushMatrix();
            glTranslated(light1_pos[0], light1_pos[1], light1_pos[2]);

            float angleX = light1_direction.angle(Vector(1, 0, 0)) * 180.0 / PI;
            float angleY = light1_direction.angle(Vector(0, 1, 0)) * 180.0 / PI;
            float angleZ = light1_direction.angle(Vector(0, 0, 1)) * 180.0 / PI;

            glRotated(-angleY, 1, 0, 0);
            glRotated(-90, 1, 0, 0);
            glutWireCone(0.5, 1, 32, 32);
        glPopMatrix();
    }
    else glDisable(GL_LIGHT1);

    glPushMatrix();
        room->update();

        glTranslated(-3, 0, 3);
        glPushMatrix();
            glTranslated(0.5, 2.34, -0.5);
            glScaled(0.5, 0.5, 0.5);
            jack->update();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.5, 2.55, 0.5);
            player->update();
        glPopMatrix();

        glTranslated(0, 0.1, 0);
        glScaled(2, 2, 2);
        table->update();
    glPopMatrix();



    glViewport(WINDOW_WIDTH/2+1, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT);

    cam.update();

    glScaled(sc, sc, sc);

    if(light0_state) {
        glEnable(GL_LIGHT0);
        glPushMatrix();
            glTranslated(light0_position[0], light0_position[1], light0_position[2]);
            glutWireSphere(0.5, 32, 32);
        glPopMatrix();
    }
    else glDisable(GL_LIGHT0);
    if(light1_state) {
        glEnable(GL_LIGHT1);
        glPushMatrix();
            glTranslated(light1_pos[0], light1_pos[1], light1_pos[2]);

            float angleX = light1_direction.angle(Vector(1, 0, 0)) * 180.0 / PI;
            float angleY = light1_direction.angle(Vector(0, 1, 0)) * 180.0 / PI;
            float angleZ = light1_direction.angle(Vector(0, 0, 1)) * 180.0 / PI;

            glRotated(-angleY, 1, 0, 0);
            glRotated(-90, 1, 0, 0);
            glutWireCone(0.5, 1, 32, 32);
        glPopMatrix();
    }
    else glDisable(GL_LIGHT1);

    glPushMatrix();
        texRoom->update();

        glTranslated(-3, 0, 3);
        glPushMatrix();
            glTranslated(0.5, 2.34, -0.5);
            glScaled(0.5, 0.5, 0.5);
            jack->update();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.5, 2.55, 0.5);
            player->update();
        glPopMatrix();

        glTranslated(0, 0.1, 0);
        glScaled(2, 2, 2);
        texTable->update();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
        exit(0);
        break;
    case 'w':
    case 'a':
    case 's':
    case 'd':
    case 'q':
    case 'e':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'u':
    case 'o':
    case 'f':
    case 'F':
        cam.handle_key(key);
        break;
    case 'm':
        light0_state = !light0_state;
        break;
    case 'M':
        light1_state = !light1_state;
        break;
    case 'b':
    case 'B':
        texRoom->handle_key(key);
        break;

    case 'z':
        sc += 0.2;
        break;
    case 'Z':
        sc -= 0.2;
        break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    //glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);


    glLightfv(GL_LIGHT0, GL_AMBIENT,  light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glLightfv(GL_LIGHT1, GL_AMBIENT,  light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 90.0); //15
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_dir);
    glLightf (GL_LIGHT1, GL_SPOT_EXPONENT, 1.0); //10

    player = new Player();
    room = new Room();
    texRoom = new RoomTextured("/home/prapti/Documents/Study/Rahat Graphics/lab6/lab6/textures/wall.jpg");
    jack = new Jack();
    table = new Table();
    texbox = new TexturedCube("/home/prapti/Documents/Study/Rahat Graphics/lab6/lab6/textures/Lenna.png", 2, 1, 1);
    texTable = new TableTextured("/home/prapti/Documents/Study/Rahat Graphics/lab6/lab6/textures/wood.jpg");

    glutMainLoop();


    return EXIT_SUCCESS;
}
