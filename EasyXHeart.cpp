// 用easyx画一个跳动的爱心，白底红心

#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415926

int main()
{
    initgraph(640, 480);
    setbkcolor(WHITE);
    setcolor(RED);
    setfillcolor(RED);
    fillcircle(320, 240, 100);
    fillcircle(220, 240, 100);
    filltriangle(220, 340, 320, 140, 420, 340);
    setcolor(WHITE);
    setfillcolor(WHITE);
    fillcircle(320, 240, 50);
    fillcircle(220, 240, 50);
    filltriangle(220, 340, 320, 190, 420, 340);
    setcolor(RED);
    setfillcolor(RED);
    fillcircle(320, 240, 20);
    fillcircle(220, 240, 20);
    filltriangle(220, 340, 320, 220, 420, 340);
    setcolor(WHITE);
    setfillcolor(WHITE);
    fillcircle(320, 240, 10);
    fillcircle(220, 240, 10);
    filltriangle(220, 340, 320, 230, 420, 340);
    setcolor(RED);
    setfillcolor(RED);
    fillcircle(320, 240, 5);
    fillcircle(220, 240, 5);
    filltriangle(220, 340, 320, 235, 420, 340);
    setcolor(WHITE);
    setfillcolor(WHITE);
    fillcircle(320, 240, 2);
    fillcircle(220, 240, 2);
    filltriangle(220, 340, 320, 238, 420, 340);
    setcolor(RED);
    setfillcolor(RED);
    fillcircle(320, 240, 1);
    fillcircle(220, 240, 1);
    filltriangle(220, 340, 320, 239, 420, 340);
    setcolor(WHITE);
    setfillcolor(WHITE);
    fillcircle(320, 240, 0.5);
    fillcircle(220, 240, 0.5);
    filltriangle(220, 340, 320, 239.5, 420, 340);
    setcolor(RED);
    setfillcolor(RED);
}