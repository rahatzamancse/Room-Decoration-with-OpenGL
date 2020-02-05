#ifndef ROOMTEXTURED_H
#define ROOMTEXTURED_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "TexturedCube.h"
#include "Material.h"

class RoomTextured : public Material::Material
{
    public:
        RoomTextured(char* filename);
        void update();
        void handle_key(int key);

    protected:
        GLfloat mat_ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        GLfloat mat_diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat shininess[1] = { 100.0f };

    private:
        unsigned int textureID;
        unsigned int fractalDepth = 0;
        TexturedCube* leftWall;
        TexturedCube* rightWalls[8];
        TexturedCube* rightWallBack;
        TexturedCube* floor;
        TexturedCube* ceil;
        TexturedCube* backWall;
        TexturedCube* frontWall;
        TexturedCube* photoFrame;

        void drawFractal(double depth, double len, double cx, double cy);
};

#endif // ROOMTEXTURED_H
