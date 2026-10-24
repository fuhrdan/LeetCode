class Solution
{
private:
    int dayOfYear(const string& date)
    {
        static const int daysPerMonth[12] =
        {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int month = (date[0] - '0') * 10 + (date[1] - '0');
        int day = (date[3] - '0') * 10 + (date[4] - '0');
        int retVal = day;

        for (int i = 0; i < month - 1; i++)
        {
            retVal += daysPerMonth[i];
        }

        return retVal;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        int start = max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = min(dayOfYear(leaveAlice), dayOfYear(leaveBob));

        return max(0, end - start + 1);
    }
};
