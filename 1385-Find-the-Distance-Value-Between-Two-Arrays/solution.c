#include <stdlib.h>

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    int retVal = 0;
    for (int i = 0; i < arr1Size; i++)
    {
        int valid = 1;
        for (int j = 0; j < arr2Size; j++)
        {
            if (abs(arr1[i] - arr2[j]) <= d)
            {
                valid = 0;
                break;
            }
        }
        if (valid) retVal++;
    }
    return retVal;
}
