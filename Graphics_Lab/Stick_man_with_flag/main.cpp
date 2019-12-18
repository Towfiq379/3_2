#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void Flag()
{
    glBegin(GL_POLYGON);
    glColor3d(0, .416, .306);
        glVertex2d(70, 400);
        glVertex2d(270, 400);
        glVertex2d(270, 280);
        glVertex2d(70, 280);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(1, .0, 0);
        for(double i = 0; i < 2 * acos(-1); i += 0.1)
            glVertex2d(160 + 40 * cos(i), 340 + 40 * sin(i));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3d(1, 1, 0);
        glVertex2d(60, 80);
        glVertex2d(60, 400);
        glVertex2d(65, 400);
        glVertex2d(65, 80);
    glEnd();

    glBegin(GL_LINES);
    glColor3d(1, 1, 1);
        glVertex2d(65, 390);
        glVertex2d(70, 390);
        glVertex2d(65, 290);
        glVertex2d(70, 290);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_LINE_LOOP);
    //glColor3d(1, .0, 0);
        for(double i = 0; i < 2 * acos(-1); i += 0.01)
            glVertex2d(-100 + 120 * cos(i), 400 + 120 * sin(i));
    glEnd();

    glBegin(GL_LINE_LOOP);
    //glColor3d(1, .0, 0);
        for(double i = 0; i < 2 * acos(-1); i += 0.01)
            glVertex2d(-140 + 20 * cos(i), 440 + 20 * sin(i));
    glEnd();

    glBegin(GL_LINE_LOOP);
    //glColor3d(1, .0, 0);
        for(double i = 0; i < 2 * acos(-1); i += 0.01)
            glVertex2d(-60 + 20 * cos(i), 440 + 20 * sin(i));
    glEnd();

    glBegin(GL_LINES);
    //glColor3d(1, .0, 0);
        glVertex2d(-100, 420);
        glVertex2d(-110, 385);

        glVertex2d(-110, 385);
        glVertex2d(-90, 385);

        glVertex2d(-90, 385);
        glVertex2d(-100, 420);
    glEnd();

    glBegin(GL_LINE_LOOP);
    //glColor3d(1, .0, 0);
        for(double i = 2 * acos(-1); i > acos(-1); i -= 0.01)
            glVertex2d(-100 + 25 * cos(i), 365 + 25 * sin(i));
    glEnd();

    glBegin(GL_LINES);
    //glColor3d(1, .0, 0);
        glVertex2d(-100, 280);
        glVertex2d(-100, -100);

        glVertex2d(-100, 200);
        glVertex2d(-260, 80);

        glVertex2d(-100, 200);
        glVertex2d(60, 80);

        glVertex2d(-100, -100);
        glVertex2d(-260, -220);

        glVertex2d(-100, -100);
        glVertex2d(60, -220);
    glEnd();

    Flag();

    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(250, 50);
    glutCreateWindow("Stick Man with flag");
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-1000, 1000, -1000, 1000);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glutDisplayFunc(display);

    glutMainLoop();
}
