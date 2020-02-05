#include "Table.h"

Table::Table() {
}

void Table::update() {
    setMaterial(mat_ambient, mat_diffuse, mat_specular, shininess);
    glPushMatrix();
        glTranslated(0, 1, 0);
        glScaled(1, 0.03, 1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.45, 0.5, 0.45);
        glScaled(0.1, 1, 0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.45, 0.5, 0.45);
        glScaled(0.1, 1, 0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.45, 0.5, -0.45);
        glScaled(0.1, 1, 0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.45, 0.5, -0.45);
        glScaled(0.1, 1, 0.1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, 0.9, -0.45);
        glScaled(0.9, 0.2, 0.03);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, 0.9, 0.45);
        glScaled(0.9, 0.2, 0.03);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.45, 0.9, 0);
        glScaled(0.03, 0.2, 0.9);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.45, 0.9, 0);
        glScaled(0.03, 0.2, 0.9);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, 0.1, 0.45);
        glScaled(1, 0.05, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, 0.1, -0.45);
        glScaled(1, 0.05, 0.05);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.45, 0.1, 0);
        glScaled(0.05, 0.05, 1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.45, 0.1, 0);
        glScaled(0.05, 0.05, 1);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, 0.1, 0);
        glScaled(0.9, 0.05, 0.05);
        glutSolidCube(1);
    glPopMatrix();
}
