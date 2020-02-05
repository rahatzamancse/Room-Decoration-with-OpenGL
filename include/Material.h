#ifndef MATERIAL_H
#define MATERIAL_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Material
{
    public:
        Material();
        void setMaterial(GLfloat mat_ambient[], GLfloat mat_diffuse[], GLfloat mat_specular[], GLfloat shininess[]);

    protected:


    private:

};

#endif // MATERIAL_H
