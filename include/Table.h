#ifndef TABLE_H
#define TABLE_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Material.h"

class Table : public Material::Material
{
    public:
        Table();
        void update();

    protected:
        GLfloat mat_ambient[4]    = { 0.7f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_diffuse[4]    = { 0.8f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat shininess[1] = { 100.0f };

    private:
};

#endif // TABLE_H
