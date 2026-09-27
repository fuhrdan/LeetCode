#include <stdint.h>

uint32_t reverseBits(uint32_t n)
{
    uint32_t retVal = 0;

    for (int i = 0; i < 32; i++)
    {
        retVal = (retVal << 1) | (n & 1U);
        n >>= 1;
    }

    return retVal;
}
