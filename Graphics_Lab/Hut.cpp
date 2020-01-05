#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;
main()
{
    cout<<">>>>>>>>>";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:");

    setcolor(WHITE);
	rectangle(150, 180, 250, 300);
	rectangle(250, 180, 420, 300);
	rectangle(180, 250, 220, 300);
	line(200, 100, 150, 180);
	line(200, 100, 250, 180);
	line(200, 100, 370, 100);
	line(370, 100, 420, 180);
	setfillstyle(SOLID_FILL, BROWN); /// pattern(0-12), color(0-15);
	floodfill(152, 182, WHITE); /// x, y, border;
	floodfill(252, 182, WHITE);
	setfillstyle(SLASH_FILL, BLUE);
	floodfill(182, 252, WHITE);
	setfillstyle(HATCH_FILL, GREEN);
	floodfill(200, 105, WHITE);
	floodfill(210, 105, WHITE);

    getch();
    closegraph();
}
