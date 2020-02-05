#include "Player.h"

Player::Player() {
}

void Player::PlayerHead(double radius, double height) {

    GLUquadric* quad = gluNewQuadric();

    // Thin
    glPushMatrix();
        glRotated(-90, 1, 0, 0);
        gluCylinder(quad, radius*0.3, radius*0.3, height, 16, 16);
    glPopMatrix();

    glPushMatrix();
        glRotated(90, 1, 0, 0);
        gluDisk(quad, 0, radius*0.3, 16, 16);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0, height, 0);
        glRotated(-90, 1, 0, 0);
        gluDisk(quad, 0, radius*0.3, 16, 16);
    glPopMatrix();


    // Thick
    glPushMatrix();
        glTranslated(0, height*0.15, 0);
        glRotated(-90, 1, 0, 0);
        gluCylinder(quad, radius, radius, height*0.7, 16, 16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, height*0.15, 0);
        glRotated(90, 1, 0, 0);
        gluDisk(quad, 0, radius, 16, 16);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0, height*0.15, 0);
        glTranslated(0, height*0.7, 0);
        glRotated(-90, 1, 0, 0);
        gluDisk(quad, 0, radius, 16, 16);
    glPopMatrix();

    gluDeleteQuadric(quad);
}

void Player::PlayerBody(double ratio) {
    GLdouble cube_vertices[] = {
        -1, -1,  1,
         1, -1,  1,
         ratio,  1,  ratio,
        -ratio,  1,  ratio,
        -1, -1, -1,
         1, -1, -1,
         ratio,  1, -ratio,
        -ratio,  1, -ratio

    };
    GLubyte cube_indices[] = {
        0, 1, 2, 3,
        1, 5, 6, 2,
        7, 6, 5, 4,
        0, 3, 7, 4,
        3, 2, 6, 7,
        4, 5, 1, 0
    };

    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer(3, GL_DOUBLE, 3 * sizeof(GLdouble), cube_vertices);
    glPushMatrix();
        glScaled(1, 2, 1);
        glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cube_indices);
    glPopMatrix();
    glDisableClientState( GL_VERTEX_ARRAY );

    GLUquadric* quad = gluNewQuadric();
    glPushMatrix();
        glTranslated(-1, -2, 0);
        glRotated(90, 0, 1, 0);
        gluCylinder(quad, 0.8, 0.8, 2, 8, 8);
        glTranslated(0, 0, 1.9);
        gluDisk(quad, 0, 0.8, 8, 8);
        glTranslated(0, 0, -1.8);
        glRotated(180, 1, 0, 0);
        gluDisk(quad, 0, 0.8, 8, 8);
    glPopMatrix();
    gluDeleteQuadric(quad);
}

void Player::PlayerLeftHand(double radius) {
    GLUquadric* quad = gluNewQuadric();

    glPushMatrix();
    glRotated(90, 1, 0, 0);
    glRotated(-30, 0, 0, 1);
    glRotated(15, 1, 0, 0);
    glutSolidSphere(radius, 16, 16);
    gluCylinder(quad, radius, radius, 0.5, 16, 16);

    glTranslated(0, 0, 0.5);
    glRotated(30, 0, 0, 1);
    glRotated(30, 1, 0, 0);
    glutSolidSphere(radius, 16, 16);
    gluCylinder(quad, radius*0.8, radius*0.6, 0.5, 16, 16);

    glTranslated(0, 0, 0.5);
    glutSolidSphere(radius*0.7, 16, 16);

    glTranslated(-0.05, 0, 0.1);
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    gluCylinder(quad, 0.08, 0.08, 0.1, 8, 8);

    glPopMatrix();
}

void Player::PlayerRightHand(double radius) {
    GLUquadric* quad = gluNewQuadric();

    glPushMatrix();
        glRotated(90, 1, 0, 0);
        glRotated(30, 0, 0, 1);
        glRotated(15, 1, 0, 0);
        glutSolidSphere(radius, 16, 16);
        gluCylinder(quad, radius, radius, 0.5, 16, 16);

        glTranslated(0, 0, 0.5);
        glutSolidSphere(radius, 16, 16);
        glRotated(-30, 0, 0, 1);
        glRotated(30, 1, 0, 0);
        gluCylinder(quad, radius*0.8, radius*0.6, 0.5, 16, 16);

        glTranslated(0, 0, 0.5);
        glutSolidSphere(radius*0.7, 16, 16);

        glTranslated(-0.05, 0, 0.1);
        glRotated(90, 1, 0, 0);
        glRotated(90, 0, 1, 0);
        gluCylinder(quad, 0.08, 0.08, 0.1, 8, 8);
    glPopMatrix();
}

void Player::PlayerLeg(double radius) {
    glPushMatrix();
        glTranslated(0, -0.55, 0);
        //Cube(1, 0.3, 0.3);
        glScaled(0.3, 1, 0.3);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0, -0.55, 0);
        glTranslated(0, -0.5, 0);
        //Cube(0.2, 0.5, 0.5);
        glScaled(0.5, 0.2, 0.5);
        glutSolidCube(1);
    glPopMatrix();
}

void Player::update() {
    if(state == WALKING) {
        if(leftRising) {
            leftHandAngle += moveSpeed;
            leftLegAngle -= moveSpeed;
            if (leftHandAngle >= riseThreshHigh)
                leftRising = false;
        }
        else {
            leftHandAngle -= moveSpeed;
            leftLegAngle += moveSpeed;
            if(leftHandAngle <= riseThreshLow)
                leftRising = true;
        }
        if(rightRising) {
            rightHandAngle += moveSpeed;
            rightLegAngle -= moveSpeed;
            if (rightHandAngle >= riseThreshHigh)
                rightRising = false;
        }
        else {
            rightHandAngle -= moveSpeed;
            rightLegAngle += moveSpeed;
            if(rightHandAngle <= riseThreshLow)
                rightRising = true;
        }
    }

    setMaterial(mat_head_ambient, mat_head_diffuse, mat_head_specular, head_shininess);
    glPushMatrix();
        glTranslated(0, 0.2, 0);
        glScaled(0.2, 0.2, 0.2);
        PlayerHead();
    glPopMatrix();

    setMaterial(mat_body_ambient, mat_body_diffuse, mat_body_specular, body_shininess);
    glPushMatrix();
        glScaled(0.1, 0.1, 0.1);
        PlayerBody();
    glPopMatrix();

    setMaterial(mat_hand_ambient, mat_hand_diffuse, mat_hand_specular, hand_shininess);
    glPushMatrix();
        glTranslated(-0.1, 0.15, 0);
        glScaled(0.3, 0.3, 0.3);
        glRotated(leftHandAngle, 1, 0, 0);
        PlayerLeftHand();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.1, 0.15, 0);
        glRotated(rightHandAngle, 1, 0, 0);
        glScaled(0.3, 0.3, 0.3);
        PlayerRightHand();
    glPopMatrix();

    setMaterial(mat_leg_ambient, mat_leg_diffuse, mat_leg_specular, leg_shininess);
    glPushMatrix();
        glTranslated(-0.07, -0.2, 0);
        glRotated(rightLegAngle, 1, 0, 0);
        glScaled(0.2, 0.2, 0.2);
        PlayerLeg();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.07, -0.2, 0);
        glRotated(leftLegAngle, 1, 0, 0);
        glScaled(0.2, 0.2, 0.2);
        PlayerLeg();
    glPopMatrix();
}
