// Truck Animationt Computer Graphics
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main()
{
    int gd = DETECT, gm;
    int i, x1, y1, x2, y2, maxx, midy;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    // Get maximum x position and calculate mid position of y-axis
    maxx = getmaxx();
    midy = getmaxy() / 2;

    // Set fixed road coordinates
    x1 = 0;
    y1 = y2 = midy + 43;
    x2 = maxx;

    // Truck animation loop, moving from left to right
    for (i = 0; i < maxx - 130; i = i + 3)
    {
        cleardevice();

        // Draw the road
        setcolor(WHITE);
        line(x1, y1, x2, y2);

        // Draw the dump bed (backside) of the truck with more details
        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        line(0 + i, midy, 80 + i, midy);
        line(80 + i, midy, 80 + i, midy + 30);
        line(80 + i, midy + 30, 47 + i, midy + 30);
        line(0 + i, midy + 30, 23 + i, midy + 30);
        line(0 + i, midy + 30, 0 + i, midy);
        arc(35 + i, midy + 30, 0, 180, 12);
        floodfill(5 + i, midy + 5, LIGHTGRAY);

        // Draw the exhaust pipe in a brighter color with outline for visibility
        setcolor(WHITE); // Outline color for visibility
        rectangle(10 + i, midy - 10, 15 + i, midy - 30);
        setfillstyle(SOLID_FILL, LIGHTGRAY); // Light color for the pipe
        floodfill(12 + i, midy - 15, WHITE);

        // Draw the cab (front) of the truck with more detail
        setcolor(LIGHTRED);
        setfillstyle(SOLID_FILL, LIGHTRED);
        line(81 + i, midy + 30, 81 + i, midy - 40);
        line(82 + i, midy - 40, 111 + i, midy - 40);
        line(111 + i, midy - 40, 126 + i, midy - 10);
        line(126 + i, midy - 10, 126 + i, midy + 30);
        line(126 + i, midy + 30, 117 + i, midy + 30);
        line(93 + i, midy + 30, 81 + i, midy + 30);
        arc(105 + i, midy + 30, 0, 180, 12);

        // Draw the truck window with a more detailed shape
        line(87 + i, midy - 5, 118 + i, midy - 5);
        line(87 + i, midy - 5, 87 + i, midy - 30);
        line(87 + i, midy - 30, 106 + i, midy - 30);
        line(106 + i, midy - 30, 118 + i, midy - 5);
        floodfill(85 + i, midy + 25, LIGHTRED);

        // Add headlight
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        rectangle(120 + i, midy, 126 + i, midy + 10);
        floodfill(122 + i, midy + 5, YELLOW);

        // Draw the truck tires with improved texture
        setcolor(DARKGRAY);
        if (i % 2 == 0)
        {
            setfillstyle(SLASH_FILL, DARKGRAY);
        }
        else
        {
            setfillstyle(BKSLASH_FILL, DARKGRAY);
        }

        circle(35 + i, midy + 30, 8);
        circle(105 + i, midy + 30, 8);
        floodfill(35 + i, midy + 30, DARKGRAY);
        floodfill(105 + i, midy + 30, DARKGRAY);

        delay(100);
    }
    getch();
    closegraph();
}
