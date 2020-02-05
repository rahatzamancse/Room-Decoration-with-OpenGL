#include "Camera.h"


Camera::Camera(int winWidth, int winHeight, Vector pos, Vector dir, Vector head) {
    WINDOW_HEIGHT = winHeight;
    WINDOW_WIDTH = winWidth;

    this->pos = pos;
    this->dir = dir.unit();
    this->head = head.unit();
}

void Camera::update() {

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy, (double)WINDOW_WIDTH/WINDOW_HEIGHT, 0.01, 300.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Vector refPoint = pos + dir;
    gluLookAt(pos.getX(), pos.getY(), pos.getZ(), refPoint.getX(), refPoint.getY(), refPoint.getZ(), head.getX(), head.getY(), head.getZ());
}

void Camera::update_ratio(int winWidth, int winHeight) {
    WINDOW_HEIGHT = winHeight;
    WINDOW_WIDTH = winWidth;
}

void Camera::handle_key(int key) {
    dir = dir.unit();
    head = head.unit();
    double ar;
    switch(key) {
    case 'w':
        pos += dir * moveVelocity;
        break;

    case 's':
        pos -= dir * moveVelocity;
        break;

    case 'a':
        pos += head.cross(dir) * moveVelocity;
        break;

    case 'd':
        pos += dir.cross(head) * moveVelocity;
        break;

    case 'q':
        pos += head * moveVelocity;
        break;

    case 'e':
        pos -= head * moveVelocity;
        break;

    case 'i':
        dir += head * rotationVelocity;
        break;

    case 'k':
        dir -= head * rotationVelocity;
        break;

    case 'l':
        dir -= head.cross(dir) * rotationVelocity;
        break;

    case 'j':
        dir += head.cross(dir) * rotationVelocity;
        break;

    case 'u':
        head += dir.cross(head) * rotationVelocity;
        break;

    case 'o':
        head += head.cross(dir) * rotationVelocity;
        break;

    case 'f':
        fovy += 5;
        break;

    case 'F':
        fovy -= 5;
        break;
    }
}
