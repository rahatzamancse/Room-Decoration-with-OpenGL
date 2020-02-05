#ifndef CAMERA_H
#define CAMERA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Vector.h"

class Camera {
    public:
        Camera(int winWidth, int winHeight, Vector pos, Vector dir, Vector head);
        void setEyePos(Vector pos);
        void setEyeDir(Vector dir);
        void setEyeHead(Vector head);

        void update();
        void update_ratio(int winWidth, int winHeight);

        void handle_key(int key);

    protected:
        Vector pos;
        Vector dir;
        Vector head;
        double moveVelocity = 0.1;
        double rotationVelocity = 0.1;

        int WINDOW_WIDTH, WINDOW_HEIGHT;
        double fovy = 60.0;

    private:

};

#endif // CAMERA_H
