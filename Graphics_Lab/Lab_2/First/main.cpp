#include <GL/glut.h>

void edit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glTranslated(-500, -500, 0);
        glScaled(2 ,.5 , 0);
        glRotated(45, 0, 0, 1);
        glBegin(GL_TRIANGLES);
        glVertex2d(0, 50);
        glVertex2d(400, 50);
        glVertex2d(0,600);
        glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1200,50);
    glutCreateWindow("Transformation of Triangle");
    glClearColor(1, 0, 0 ,1);
    glColor3d(0, 0, 0);

    glutDisplayFunc(display);
    edit();

    glutMainLoop();
}
