class Solution
{
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d)
    {
        int retVal = 0;
        for (int value1 : arr1)
        {
            boolean valid = true;
            for (int value2 : arr2)
            {
                if (Math.abs(value1 - value2) <= d)
                {
                    valid = false;
                    break;
                }
            }
            if (valid) retVal++;
        }
        return retVal;
    }
}
