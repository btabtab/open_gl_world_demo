#ifndef SHAPE_CLASS_H_INCLUDED
#define SHAPE_CLASS_H_INCLUDED

class shape
{
private:

    int point_count;

    GLfloat points_X[5]
    =
    {-0.4, +0.4, +0.4};///X

    GLfloat points_Y[5]
    =
    {-0.4, -0.4, +0.4};///Y


public:

    void render(int point_total)
    {
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i != point_total; i++)
            glVertex2f(points_X[i], points_Y[i]);

        glEnd();
    }

};

shape triangle;
#endif // SHAPE_CLASS_H_INCLUDED
