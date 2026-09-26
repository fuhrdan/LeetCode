//*****************************************************************************
//** 3550. Smallest Index With Digit Sum Equal to Index             leetcode **
//*****************************************************************************

int smallestIndex(int* nums, int numsSize) {
    for(int i = 0; i < numsSize; i++)
    {
        int num = nums[i];
        int sum = 0;

        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        if (sum == i)
        {
            return i;
        }
    }
    return -1;
}