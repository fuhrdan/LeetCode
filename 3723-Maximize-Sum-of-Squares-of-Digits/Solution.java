class Solution
{
    public String maxSumOfSquares(int num, int sum)
    {
        if (sum > num * 9)
        {
            return "";
        }

        int fullNines = sum / 9;
        int remainder = sum % 9;
        StringBuilder retVal = new StringBuilder(num);

        for (int i = 0; i < fullNines; i++)
        {
            retVal.append('9');
        }

        if (remainder > 0)
        {
            retVal.append((char)('0' + remainder));
        }

        while (retVal.length() < num)
        {
            retVal.append('0');
        }

        return retVal.toString();
    }
}
