class Solution
{
public:
    string maxSumOfSquares(int num, int sum)
    {
        if (sum > num * 9)
        {
            return "";
        }

        int fullNines = sum / 9;
        int remainder = sum % 9;

        string retVal(fullNines, '9');

        if (remainder > 0)
        {
            retVal.push_back(static_cast<char>('0' + remainder));
        }

        retVal.append(num - static_cast<int>(retVal.size()), '0');

        return retVal;
    }
};
