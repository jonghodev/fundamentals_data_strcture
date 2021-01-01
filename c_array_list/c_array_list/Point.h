#ifndef Point_h
#define Point_h

#include <stdio.h>

typedef struct _point
{
    int xpos;
    int ypos;
} Point;

void SetPointPos(Point * ppos, int xpos, int ypos);

void ShowPointPos(Point * ppos);

int PointComp(Point * pos1, Point * pos2);

#endif
