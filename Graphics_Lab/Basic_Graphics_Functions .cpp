#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;
main()
{
    int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;
    initgraph(&gd, &gm, "C:");

    cleardevice();
    setbkcolor(GREEN);
    //setcolor(RED); /// color(0-15);
    cout << getmaxx() << ' ' << getmaxy() << endl;
    rectangle(left-80, top-80, right+80, bottom+80);
    circle(x + 200, y + 200, radius);
    bar(left + 300, top, right + 300, bottom);
    bar3d(left + 300, top, right + 300, bottom, 50, 1); /// depth, flag
    line(left - 10, top + 150, left + 410, top + 150);
    ellipse(x, y + 200, 0, 360, 100, 50);/// h, k, starting_angle, ending_angle, x_rad, y_rad;
    fillellipse(x, y + 200, 100, 50);/// h, k, x_rad, y_rad;
    int ar[] = {10, 10, 100, 10, 10, 100, 10, 10};
    drawpoly(4, ar); /// num_of_points, *points;
    arc(100, 100, 0, 90, 50); /// h, k, starting_angle, ending_angle, rad;
    pieslice(100, 100, 0, 90, 80); /// h, k, starting_angle, ending_angle, rad;
    sector(100, 100, 0, 90, 100, 50);/// h, k, starting_angle, ending_angle, x_rad, y_rad;
    settextstyle(1, 1, 0); /// font(0-4), direction(0-1), size;
    outtextxy(100, 10, "My First C Graphics Program"); /// left, top, string;
    setfillstyle(SOLID_FILL, BROWN); /// pattern(0-12), color(0-15);
	floodfill(x + 200, y + 200, WHITE); /// x, y, border;
    getch();
    closegraph();
}
