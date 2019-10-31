#include<bits/stdc++.h>
#include<dos.h>
#include<graphics.h>
using namespace std;

void Bresenham(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int flag)
{
    int x, y, xx, yy, dx, dy, dS, dT, d;
    int slope = 1;
    if(x2 - x1 < 0)
        slope *= -1;
    if(y2 - y1 < 0)
        slope *= -1;

    if(abs(y2 - y1) <= abs(x2 - x1) && slope == 1)
    {
        if(x1 > x2)
            swap(x1, x2), swap(y1, y2), swap(x3, x4), swap(y3, y4);
        x = x1, y = y1, xx = x4, yy = y4;
        dx = x2 - x1, dy = y2 - y1;
        dS = 2 * dy, dT = 2 * dy - 2 * dx;
        d = 2 * dy - dx;
        while(x <= x2)
        {
            if(flag)
                putpixel(x, y, RED);
            else
                Bresenham(x, y, xx, yy, 0, 0, 0, 0, 1);
            if(d < 0)
                d += dS;
            else
                y++, yy++, d += dT;
            x++, xx++;
        }
    }

    else if(abs(y2 - y1) <= abs(x2 - x1) && slope == -1)
    {
        if(x1 > x2)
            swap(x1, x2), swap(y1, y2), swap(x3, x4), swap(y3, y4);
        x = x1, y = y1, xx = x4, yy = y4;
        dx = x2 - x1, dy = y2 - y1;
        dS = 2 * dx + 2 * dy, dT = 2 * dy;
        d = 2 * dy + dx;
        while(x <= x2)
        {
            if(flag)
                putpixel(x, y, RED);
            else
                Bresenham(x, y, xx, yy, 0, 0, 0, 0, 1);
            if(d < 0)
                y--, yy--, d += dS;
            else
                d += dT;
            x++, xx++;
        }
    }

    else if(abs(y2 - y1) >= abs(x2 - x1) && slope == 1)
    {
        if(y1 > y2)
            swap(x1, x2), swap(y1, y2), swap(x3, x4), swap(y3, y4);
        x = x1, y = y1, xx = x4, yy = y4;
        dx = x2 - x1, dy = y2 - y1;
        dS = 2 * dx, dT = 2 * dx - 2 * dy;
        d = 2 * dx - dy;
        while(y <= y2)
        {
            if(flag)
                putpixel(x, y, RED);
            else
                Bresenham(x, y, xx, yy, 0, 0, 0, 0, 1);
            if(d < 0)
                d += dS;
            else
                x++, xx++, d += dT;
            y++, yy++;
        }
    }

    else
    {
        if(y1 > y2)
            swap(x1, x2), swap(y1, y2), swap(x3, x4), swap(y3, y4);
        x = x1, y = y1;
        dx = x2 - x1, dy = y2 - y1, xx = x4, yy = y4;
        dS = 2 * dx + 2 * dy, dT = 2 * dx;
        d = 2 * dx + dy;
        while(y <= y2)
        {
            if(flag)
                putpixel(x, y, RED);
            else
                Bresenham(x, y, xx, yy, 0, 0, 0, 0, 1);
            if(d < 0)
                x--, xx--, d += dS;
            else
                d += dT;
            y++, yy++;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:");
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    Bresenham(x1, y1, x2, y2, x3, y3, x4, y4, 0);
    getch();
    closegraph();
}
/*
10 100
100 100
100 10
10 10

100 300
200 400
400 200
300 100
*/
