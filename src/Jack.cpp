#include "Jack.h"


Jack::Jack(int slices, int stacks) {
    this->slices = slices;
    this->stacks = stacks;
}

void Jack::update() {
    setMaterial(mat_ambient, mat_diffuse, mat_specular, shininess);
    glPushMatrix();
        glRotated(45, 1, 0, 0);
        glRotated(45, 0, 0, 1);
        glTranslated(0, 0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glRotated(-45, 1, 0, 0);
        glRotated(45, 0, 0, 1);
        glTranslated(0, 0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glRotated(45, 1, 0, 0);
        glRotated(-45, 0, 0, 1);
        glTranslated(0, 0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glRotated(-45, 1, 0, 0);
        glRotated(-45, 0, 0, 1);
        glTranslated(0, 0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glRotated(45+90, 1, 0, 0);
        glRotated(45+90, 0, 0, 1);
        glTranslated(0, -0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glRotated(-45-90, 1, 0, 0);
        glRotated(45+90, 0, 0, 1);
        glTranslated(0, -0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glRotated(45+90, 1, 0, 0);
        glRotated(-45-90, 0, 0, 1);
        glTranslated(0, -0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glRotated(-45-90, 1, 0, 0);
        glRotated(-45-90, 0, 0, 1);
        glTranslated(0, -0.2*3/2, 0);
        glScaled(1, 3, 1);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    double x=0.42, y=0.32, z=0.32;

    glPushMatrix();
        glTranslated(x, y, z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-x, y, z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x, -y, z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x, y, -z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-x, -y, z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-x, y, -z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(x, -y, -z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-x, -y, -z);
        glutSolidSphere(0.1, slices, stacks);
    glPopMatrix();
}
