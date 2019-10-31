#include<bits/stdc++.h>
#include<dos.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:");

    int x1, y1, x2, y2, x, y, dx, dy, dS, dT, d;
    while(1)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int slope = 1;
        if(x2 - x1 < 0)
            slope *= -1;
        if(y2 - y1 < 0)
            slope *= -1;

        if(abs(y2 - y1) <= abs(x2 - x1) && slope == 1)
        {
            if(x1 > x2)
                swap(x1, x2), swap(y1, y2);
            x = x1, y = y1;
            dx = x2 - x1, dy = y2 - y1;
            dS = 2 * dy, dT = 2 * dy - 2 * dx;
            d = 2 * dy - dx;
            while(x <= x2)
            {
                putpixel(x, y, WHITE);
                if(d < 0)
                    d += dS;
                else
                    y++, d += dT;
                x++;
            }
        }

        else if(abs(y2 - y1) <= abs(x2 - x1) && slope == -1)
        {
            if(x1 > x2)
                swap(x1, x2), swap(y1, y2);
            x = x1, y = y1;
            dx = x2 - x1, dy = y2 - y1;
            dS = 2 * dx + 2 * dy, dT = 2 * dy;
            d = 2 * dy + dx;
            while(x <= x2)
            {
                putpixel(x, y, WHITE);
                if(d < 0)
                    y--, d += dS;
                else
                    d += dT;
                x++;
            }
        }

        else if(abs(y2 - y1) >= abs(x2 - x1) && slope == 1)
        {
            if(y1 > y2)
                swap(x1, x2), swap(y1, y2);
            x = x1, y = y1;
            dx = x2 - x1, dy = y2 - y1;
            dS = 2 * dx, dT = 2 * dx - 2 * dy;
            d = 2 * dx - dy;
            while(y <= y2)
            {
                putpixel(x, y, WHITE);
                if(d < 0)
                    d += dS;
                else
                    x++, d += dT;
                y++;
            }
        }

        else
        {
            if(y1 > y2)
                swap(x1, x2), swap(y1, y2);
            x = x1, y = y1;
            dx = x2 - x1, dy = y2 - y1;
            dS = 2 * dx + 2 * dy, dT = 2 * dx;
            d = 2 * dx + dy;
            while(y <= y2)
            {
                putpixel(x, y, WHITE);
                if(d < 0)
                    x--, d += dS;
                else
                    d += dT;
                y++;
            }
        }
    }

    getch();
    closegraph();
}

/*
10 10
100 10

10 10
40 200

40 200
200 100

200 100
100 10
*/
