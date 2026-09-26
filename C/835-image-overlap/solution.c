//*****************************************************************************
//** 835. Image Overlap                                             leetcode **
//*****************************************************************************

int largestOverlap(int** img1, int img1Size, int* img1ColSize,
                   int** img2, int img2Size, int* img2ColSize)
{
    int n = img1Size;
    int maxOverlap = 0;

    for (int rowShift = -(n - 1); rowShift <= n - 1; rowShift++)
    {
        for (int colShift = -(n - 1); colShift <= n - 1; colShift++)
        {
            int overlap = 0;

            for (int row = 0; row < n; row++)
            {
                for (int col = 0; col < n; col++)
                {
                    int row2 = row + rowShift;
                    int col2 = col + colShift;

                    if (row2 >= 0 && row2 < n &&
                        col2 >= 0 && col2 < n &&
                        img1[row][col] == 1 &&
                        img2[row2][col2] == 1)
                    {
                        overlap++;
                    }
                }
            }

            if (overlap > maxOverlap)
            {
                maxOverlap = overlap;
            }
        }
    }

    return maxOverlap;
}