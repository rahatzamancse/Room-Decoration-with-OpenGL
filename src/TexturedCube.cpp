#include "TexturedCube.h"

TexturedCube::TexturedCube(char* filename, double width, double height, double length) {
    this->height = height; this->width = width; this->length = length;
    int imwidth, imheight, nrChannels;
    unsigned char *data = stbi_load(filename, &imwidth, &imheight, &nrChannels, STBI_rgb);
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    //Defines parameters for texture coordinate generation
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imwidth, imheight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

    stbi_image_free(data);
}

void TexturedCube::update() {
    double sizes[] = {
        width, height, // front
        width, height, // back
        length, height, // left
        length, height, // right
        width, length, // top
        width, length // bottom
    };

    double rotations[] = {
        180, 0, 1, 0,
        0, 0, 1, 0,
        -90, 0, 1, 0,
        90, 0, 1, 0,
        -90, 1, 0, 0,
        90, 1, 0, 0
    };

    double translations[] = {
        0, 0, -length/2,
        0, 0, +length/2,
        -width/2, 0, 0,
        width/2, 0, 0,
        0, height/2, 0,
        0, -height/2, 0
    };

    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glRotated(180, 0, 0, 1);
        for(int i=0; i<6; i++) {
            glPushMatrix();
                glTranslated(translations[i*3+0], translations[i*3+1], translations[i*3+2]);
                glRotated(rotations[i*4], rotations[i*4+1], rotations[i*4+2], rotations[i*4+3]);
                glTranslated(-sizes[2*i + 0]/2, -sizes[2*i + 1]/2, 0);
                glBegin(GL_QUADS);
                    glVertex3d(0,              0,              0);
                    glVertex3d(sizes[2*i + 0], 0,              0);
                    glVertex3d(sizes[2*i + 0], sizes[2*i + 1], 0);
                    glVertex3d(0,              sizes[2*i + 1], 0);

//                    glVertex3d(-sizes[2*i + 0]/2, -sizes[2*i + 1]/2, 0);
//                    glVertex3d(-sizes[2*i + 0]/2,  sizes[2*i + 1]/2, 0);
//                    glVertex3d( sizes[2*i + 0]/2,  sizes[2*i + 1]/2, 0);
//                    glVertex3d( sizes[2*i + 0]/2, -sizes[2*i + 1]/2, 0);
                glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
