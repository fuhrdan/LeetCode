class Solution
{
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        int retVal = 0;
        for (int value1 : arr1)
        {
            bool valid = true;
            for (int value2 : arr2)
            {
                if (abs(value1 - value2) <= d)
                {
                    valid = false;
                    break;
                }
            }
            if (valid) retVal++;
        }
        return retVal;
    }
};
