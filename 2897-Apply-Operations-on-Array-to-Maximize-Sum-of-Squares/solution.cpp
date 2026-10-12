class Solution
{
public:
    int maxSum(vector<int>& nums, int k)
    {
        static const int MOD = 1000000007;
        static const int BITS = 31;

        vector<int> bitCount(BITS, 0);

        for (int value : nums)
        {
            for (int bit = 0; bit < BITS; bit++)
            {
                if ((value >> bit) & 1)
                {
                    bitCount[bit]++;
                }
            }
        }

        long long retVal = 0;

        for (int i = 0; i < k; i++)
        {
            long long value = 0;

            for (int bit = 0; bit < BITS; bit++)
            {
                if (bitCount[bit] > 0)
                {
                    value |= 1LL << bit;
                    bitCount[bit]--;
                }
            }

            long long modValue = value % MOD;
            retVal = (retVal + (modValue * modValue) % MOD) % MOD;
        }

        return static_cast<int>(retVal);
    }
};
