#include "TableTextured.h"

TableTextured::TableTextured(char* filename) {
    double sized[] = {
        1, 0.03, 1,
        0.1, 1, 0.1,
        0.1, 1, 0.1,
        0.1, 1, 0.1,
        0.1, 1, 0.1,
        0.9, 0.2, 0.03,
        0.9, 0.2, 0.03,
        0.03, 0.2, 0.9,
        0.03, 0.2, 0.9,
        1, 0.05, 0.05,
        1, 0.05, 0.05,
        0.05, 0.05, 1,
        0.05, 0.05, 1,
        0.9, 0.05, 0.05,
    };

    for(int i=0; i<14; i++) {
        parts[i] = new TexturedCube(filename, sized[i*3+0], sized[i*3+1], sized[i*3+2]);
    }

}

void TableTextured::update() {
    double translations[] = {
        0, 1, 0,
        0.45, 0.5, 0.45,
        -0.45, 0.5, 0.45,
        0.45, 0.5, -0.45,
        -0.45, 0.5, -0.45,
        0, 0.9, -0.45,
        0, 0.9, 0.45,
        0.45, 0.9, 0,
        -0.45, 0.9, 0,
        0, 0.1, 0.45,
        0, 0.1, -0.45,
        -0.45, 0.1, 0,
        0.45, 0.1, 0,
        0, 0.1, 0
    };

    setMaterial(mat_ambient, mat_diffuse, mat_specular, shininess);
    for(int i=0; i<14; i++) {
        glPushMatrix();
            glTranslated(translations[i*3+0], translations[i*3+1], translations[i*3+2]);
            parts[i]->update();
        glPopMatrix();
    }
}
