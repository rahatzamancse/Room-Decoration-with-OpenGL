#ifndef ROOM_H
#define ROOM_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Material.h"

class Room : public Material::Material
{
    public:
        Room();
        void update();

    protected:
        GLfloat mat_ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        GLfloat mat_diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat shininess[1] = { 100.0f };

    private:
};

#endif // ROOM_H
