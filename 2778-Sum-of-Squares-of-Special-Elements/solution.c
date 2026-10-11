int sumOfSquares(int* nums, int numsSize)
{
    int retVal = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int index = i + 1;

        if (numsSize % index == 0)
        {
            retVal += nums[i] * nums[i];
        }
    }

    return retVal;
}
