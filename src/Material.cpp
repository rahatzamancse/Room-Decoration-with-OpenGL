#include "Material.h"

Material::Material() {
}


void Material::setMaterial(GLfloat mat_ambient[], GLfloat mat_diffuse[], GLfloat mat_specular[], GLfloat high_shininess[]) {
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
