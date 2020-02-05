#ifndef TEXTUREDCUBE_H
#define TEXTUREDCUBE_H

#ifndef STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif // STB_IMAGE_IMPLEMENTATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class TexturedCube
{
    public:
        TexturedCube(char *texfilename, double width=1, double height=1, double length=1);
        void update();

    protected:

    private:
        unsigned int textureID = 0;
        double width, height, length;
};

#endif // TEXTUREDCUBE_H
