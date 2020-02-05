#include "RoomTextured.h"

RoomTextured::RoomTextured(char* filename) {
    frontWall = new TexturedCube(filename, 10, 10, 0.2);
    leftWall = new TexturedCube(filename, 10, 10, 0.2);
    backWall = new TexturedCube(filename, 10, 10, 0.2);
    rightWallBack = new TexturedCube("/home/prapti/Documents/Study/Rahat Graphics/lab6/lab6/textures/scenary.jpg", 2, 2, 0.1);
    for(int i=0; i<8; i++) rightWalls[i] = new TexturedCube(filename, 3.25, 3.25, 0.2);
    photoFrame = new TexturedCube("/home/prapti/Documents/Study/Rahat Graphics/lab6/lab6/textures/Lenna.png", 1, 1, 0.15);
}


void RoomTextured::drawFractal(double depth, double len, double cx, double cy) {
    glBegin(GL_QUADS);
        glVertex2d(cx-len/2, cy+len/2);
        glVertex2d(cx+len/2, cy+len/2);
        glVertex2d(cx+len/2, cy-len/2);
        glVertex2d(cx-len/2, cy-len/2);
    glEnd();

    if(depth == 0) return;
    depth--;

    drawFractal(depth, len/2, cx-len/2, cy+len/2);
    drawFractal(depth, len/2, cx+len/2, cy+len/2);
    drawFractal(depth, len/2, cx+len/2, cy-len/2);
    drawFractal(depth, len/2, cx-len/2, cy-len/2);
}

void RoomTextured::handle_key(int key) {
    switch(key) {
    case 'b':
        fractalDepth += 1;
        break;
    case 'B':
        if(fractalDepth > 0) fractalDepth -= 1;
        break;
    }
}

void RoomTextured::update() {
    setMaterial(mat_ambient, mat_diffuse, mat_specular, shininess);

    // Front
    glPushMatrix();
        glTranslated(0, 5, 5);
        glPushMatrix();
            glTranslated(0, 0, -0.25);
            glScaled(4, 4, 0.01);
            glPushMatrix();
                GLfloat mat_ambient1[4]    = { 0.5f, 0.0f, 0.0f, 1.0f };
                GLfloat mat_diffuse1[4]    = { 1.0f, 0.0f, 0.0f, 1.0f };
                GLfloat mat_specular1[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
                GLfloat shininess1[1] = { 100.0f };
                setMaterial(mat_ambient1, mat_diffuse1, mat_specular1, shininess1);
                glTranslated(0, 0, -0.51);
                drawFractal(fractalDepth, 0.45, 0, 0);
                setMaterial(mat_ambient, mat_diffuse, mat_specular, shininess);
            glPopMatrix();
            glutSolidCube(1);
        glPopMatrix();
        backWall->update();
    glPopMatrix();

    // Right
    glPushMatrix();
        glTranslated(-5, 5, 0);
        glRotated(90, 0, 1, 0);

        glPushMatrix();
            glTranslated(0, -10, -8);
            glScaled(20, 20, 0.1);
            rightWallBack->update();
        glPopMatrix();

        glPushMatrix();
            glTranslated(3.25, 0, 0);
            rightWalls[0]->update();
        glPopMatrix();
        glPushMatrix();
            glTranslated(-3.25, 0, 0);
            rightWalls[1]->update();
        glPopMatrix();
        glPushMatrix();
            glTranslated(0, 3.25, 0);
            rightWalls[2]->update();
        glPopMatrix();
        glPushMatrix();
            glTranslated(0, -3.25, 0);
            rightWalls[3]->update();
        glPopMatrix();
        glPushMatrix();
            glTranslated(3.25, -3.25, 0);
            rightWalls[4]->update();
        glPopMatrix();
        glPushMatrix();
            glTranslated(3.25, 3.25, 0);
            rightWalls[5]->update();
        glPopMatrix();
        glPushMatrix();
            glTranslated(-3.25, -3.25, 0);
            rightWalls[6]->update();
        glPopMatrix();
        glPushMatrix();
            glTranslated(-3.25, 3.25, 0);
            rightWalls[7]->update();
        glPopMatrix();
    glPopMatrix();

    // Back
    glPushMatrix();
        glTranslated(0, 5, -5);
        backWall->update();
    glPopMatrix();

    // Left
    glPushMatrix();
        glTranslated(5, 5, 0);
        glRotated(90, 0, 1, 0);
        glPushMatrix();
            glTranslated(0, 0, -0.15);
            glScaled(3, 3, 1);
            photoFrame->update();
        glPopMatrix();
        leftWall->update();
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
