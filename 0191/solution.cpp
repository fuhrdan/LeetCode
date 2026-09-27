#include <cstdint>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int retVal = 0;

        while (n != 0)
        {
            n &= n - 1;
            retVal++;
        }

        return retVal;
    }
};
