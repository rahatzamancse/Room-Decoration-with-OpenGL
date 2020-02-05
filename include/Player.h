#ifndef PLAYER_H
#define PLAYER_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Material.h"


class Player : public Material::Material
{
    public:
        Player();
        void update();

    protected:
        bool leftRising = true;
        bool rightRising = false;
        bool moving = false;

        double moveSpeed = 3;
        double riseThreshHigh = 50;
        double riseThreshLow = -30;

        double leftHandAngle = riseThreshLow;
        double rightHandAngle = riseThreshHigh;
        double leftLegAngle = riseThreshHigh;
        double rightLegAngle = riseThreshLow;

        enum {
            STANDING, WALKING
        } state = STANDING;

        double velocity = 0.01;

        double dirX = 0;
        double dirY = 0;
        double dirZ = 0;

        void PlayerHead(double radius=0.3, double height=1);
        void PlayerBody(double ratio=0.7);
        void PlayerLeftHand(double radius=0.1);
        void PlayerRightHand(double radius=0.1);
        void PlayerLeg(double radius=0.2);


        GLfloat mat_head_ambient[4]    = { 0.1f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_head_diffuse[4]    = { 0.0588f, 0.8235f, 0.08235f, 1.0f };
        GLfloat mat_head_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat head_shininess[1] = { 100.0f };

        GLfloat mat_body_ambient[4]    = { 0.1f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_body_diffuse[4]    = { 0.18f, 0.203f, 0.7803f, 1.0f };
        GLfloat mat_body_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat body_shininess[1] = { 100.0f };

        GLfloat mat_hand_ambient[4]    = { 0.1f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_hand_diffuse[4]    = { 0.7764f, 0.8078f, 0.2078f, 1.0f };
        GLfloat mat_hand_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat hand_shininess[1] = { 100.0f };

        GLfloat mat_leg_ambient[4]    = { 0.1f, 0.1f, 0.1f, 1.0f };
        GLfloat mat_leg_diffuse[4]    = { 0.7764f, 0.8078f, 0.2078f, 1.0f };
        GLfloat mat_leg_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat leg_shininess[1] = { 100.0f };

    private:

};

#endif // PLAYER_H
