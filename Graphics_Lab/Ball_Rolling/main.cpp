#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void display()
{
    //glClear(GL_COLOR_BUFFER_BIT);
    for(double j = 0; j < 900; j++)
    {
        glFlush();
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
            glTranslated(j, 0, 0);
            glRotated(-9 * j / 5 / acos(-1), 0 ,0, 1);
            glBegin(GL_POLYGON);
            glColor3d(0, 0, 1);
            double i = 0;
            for( ; i < acos(-1); i += 0.1)
                glVertex2d(100 * cos(i), 100 * sin(i));
            glColor3d(1, 0, 0);
            for( ; i < 2 * acos(-1); i += 0.1)
                glVertex2d(100 * cos(i), 100 * sin(i));
            glEnd();
        glPopMatrix();
        Sleep(1);
    }
    //glFlush();
    //glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(250, 50);
    glutCreateWindow("Ball Rolling");
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1000, 1000, -1000, 1000);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glutDisplayFunc(display);

    glutMainLoop();
}
