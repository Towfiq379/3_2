#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3d(0, .416, .306);
        glVertex2d(-600, 800);
        glVertex2d(0, 800);
        glVertex2d(0, 440);
        glVertex2d(-600, 440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(1, .0, 0);
        for(double i = 0; i < 2 * acos(-1); i += 0.1)
            glVertex2d(-330 + 120 * cos(i), 620 + 120 * sin(i));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(1, 1, 0);
        glVertex2d(-650, 800);
        glVertex2d(-625, 800);
        glVertex2d(-625, -100);
        glVertex2d(-650, -100);
    glEnd();

    glBegin(GL_LINES);
    glColor3d(1, 1, 1);
        glVertex2d(-625, 780);
        glVertex2d(-600, 780);
        glVertex2d(-625, 460);
        glVertex2d(-600, 460);
    glEnd();

    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(600, 500);
    glutInitWindowPosition(850, 50);
    glutCreateWindow("National flag of Bangladesh");
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1000, 1000, -1000, 1000);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glutDisplayFunc(display);

    glutMainLoop();
}
