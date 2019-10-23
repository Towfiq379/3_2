#include<bits/stdc++.h>
#include <GL/glut.h>
#define F first
#define S second
#define pdd pair<double, double>
using namespace std;
const int MX = 100;
int P_SZ, C_SZ;

pdd Clipper[MX], polygon[MX];

pdd Intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double x = ((x1*y2 - y1*x2) * (x3-x4) - (x1-x2) * (x3*y4 - y3*x4)) / ((x1-x2) * (y3-y4) - (y1-y2) * (x3-x4));
    double y = ((x1*y2 - y1*x2) * (y3-y4) - (y1-y2) * (x3*y4 - y3*x4)) / ((x1-x2) * (y3-y4) - (y1-y2) * (x3-x4));
    return {x, y};
}

void Clip(double x1, double y1, double x2, double y2)
{
    pdd New_Points[MX];
    int New_SZ = 0;
    for(int i = 0; i < P_SZ; i++)
    {
        int j = (i + 1) % P_SZ;
        double x3 = polygon[i].F, y3 = polygon[i].S;
        double x4 = polygon[j].F, y4 = polygon[j].S;
        double pos1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        double pos2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);

        if(pos1 < 0 && pos2 < 0)
        {
            New_Points[New_SZ] = {x4, y4};
            New_SZ++;
        }

        else if(pos1 >=0 && pos2 < 0)
        {
            New_Points[New_SZ] = Intersection(x1, y1, x2, y2, x3, y3, x4, y4);
            New_SZ++;
            New_Points[New_SZ] = {x4, y4};
            New_SZ++;
        }

        else if(pos1 < 0 && pos2 >= 0)
        {
            New_Points[New_SZ] = Intersection(x1, y1, x2, y2, x3, y3, x4, y4);
            New_SZ++;
        }
    }
    P_SZ = New_SZ;
    cout << P_SZ << endl;
    for(int i = 0; i < P_SZ; i++)
        polygon[i]=New_Points[i];
}

void polygon_Clipping()
{
    for(int i = 0; i < C_SZ; i++)
    {
        int j = (i + 1) % C_SZ;
        Clip(Clipper[i].F, Clipper[i].S, Clipper[j].F, Clipper[j].S);
    }

    for(int i = 0; i < P_SZ; i++)
        cout << fixed << setprecision(2) << polygon[i].F << ' ' << polygon[i].S << endl;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3d(1, 0, 0);
        for(int i = 0; i < C_SZ; i++)
            glVertex2d(Clipper[i].F, Clipper[i].S);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3d(0, 0, 1);
        for(int i = 0; i < P_SZ; i++)
            glVertex2d(polygon[i].F, polygon[i].S);
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    cin >> P_SZ;
    for(int i = 0; i < P_SZ; i++)
        cin >> polygon[i].F >> polygon[i].S;

    cin >> C_SZ;
    for(int i = 0; i < C_SZ; i++)
        cin >> Clipper[i].F >> Clipper[i].S;
    polygon_Clipping();


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(850, 50);
    glutCreateWindow("Polygon Clipping");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000, 1000, -1000, 1000);

    glutDisplayFunc(display);

    glutMainLoop();
}
/*
3
400 600
800 1000
1200 800
4
600 600
600 800
800 800
800 600
*/
