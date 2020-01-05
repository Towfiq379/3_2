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
    int p = 1 - r;
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
        if(p < 0)
            p += 2 * x + 3;
        else
            p += 2 * x - 2 * y + 5, y--;
        x++;
    }

    getch();
    closegraph();
}

/*
100 80
60
*/
