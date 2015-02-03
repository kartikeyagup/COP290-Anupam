#include <bits/stdc++.h>
#include <GL/freeglut.h>

using namespace std;

Create3DBox::Create3DBox(Vect* dim, colorbox col)
{
	dimension = dim;
	colour = col;
}

void Create3DBox::makeQuads(float* cords, float* color)
{
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(cords[a]);

    glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}
