#include "Room.h"

Room::Room()
{

}

void Room::update() {
    setMaterial(mat_ambient, mat_diffuse, mat_specular, shininess);

    // Front
    glPushMatrix();
        glTranslated(0, 5, 5);
        glScaled(10, 10, 0.2);
        glPushMatrix();
            glTranslated(0, 0, -0.45);
            glScaled(0.25, 0.25, 0.5);
            glutSolidCube(1);
        glPopMatrix();
        glutSolidCube(1);
    glPopMatrix();

    // Right
    glPushMatrix();
        glTranslated(-5, 5, 0);

        glRotated(90, 0, 1, 0);
        glScaled(3.25, 3.25, 0.2);

        glPushMatrix();
            glTranslated(1, 0, 0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslated(-1, 0, 0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslated(0, 1, 0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslated(0, -1, 0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslated(-1, -1, 0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslated(-1, 1, 0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslated(1, -1, 0);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslated(1, 1, 0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

    // Back
    glPushMatrix();
        glTranslated(0, 5, -5);
        glScaled(10, 10, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    // Left
    glPushMatrix();
        glTranslated(5, 5, 0);
        glRotated(90, 0, 1, 0);
        glPushMatrix();
            glTranslated(0, 0, -0.15);
            glScaled(3, 3, 0.15);
            glutSolidCube(1);
        glPopMatrix();
        glScaled(10, 10, 0.2);
        glutSolidCube(1);
    glPopMatrix();

    // Floor
    glPushMatrix();
        glScaled(10, 0.2, 10);
        glutSolidCube(1);
    glPopMatrix();

    // Ceil
    glPushMatrix();
        glTranslated(0, 10, 0);
        glScaled(10, 0.2, 10);
        glutSolidCube(1);
    glPopMatrix();

}
