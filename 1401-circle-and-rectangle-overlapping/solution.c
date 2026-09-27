//*****************************************************************************
//** 1401. Circle and Rectangle Overlapping                         leetcode **
//*****************************************************************************

bool checkOverlap(int radius, int xCenter, int yCenter,
                  int x1, int y1, int x2, int y2)
{
    int closestX = xCenter;
    int closestY = yCenter;

    if (closestX < x1)
    {
        closestX = x1;
    }
    else if (closestX > x2)
    {
        closestX = x2;
    }

    if (closestY < y1)
    {
        closestY = y1;
    }
    else if (closestY > y2)
    {
        closestY = y2;
    }

    int dx = xCenter - closestX;
    int dy = yCenter - closestY;

    bool retVal = (dx * dx + dy * dy) <= (radius * radius);

    return retVal;
}