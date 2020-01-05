#include<bits/stdc++.h>
#include<dos.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:");

    int h, k, r;
    cin >> h >> k >> r;
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while(x <= y)
    {
        putpixel(h + x, k + y, WHITE);
        putpixel(h + x, k - y, WHITE);
        putpixel(h - x, k + y, WHITE);
        putpixel(h - x, k - y, WHITE);
        putpixel(h + y, k + x, WHITE);
        putpixel(h + y, k - x, WHITE);
        putpixel(h - y, k + x, WHITE);
        putpixel(h - y, k - x, WHITE);
        if(d < 0)
            d += 4 * x + 6;
        else
            d += 4 * x - 4 * y + 10, y--;
        x++;
    }

    getch();
    closegraph();
}

/*
100 80
60
*/
