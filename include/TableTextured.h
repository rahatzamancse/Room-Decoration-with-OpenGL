#ifndef TABLETEXTURED_H
#define TABLETEXTURED_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "TexturedCube.h"
#include "Material.h"


class TableTextured : public Material::Material
{
    public:
        TableTextured(char* filename);
        void update();

    protected:
        GLfloat mat_ambient[4]    = { 0.7f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_diffuse[4]    = { 0.8f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat shininess[1] = { 100.0f };

    private:
        TexturedCube* parts[14];
};

#endif // TABLETEXTURED_H
