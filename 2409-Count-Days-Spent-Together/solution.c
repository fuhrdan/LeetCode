static int dayOfYear(const char* date)
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

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob)
{
    int start = dayOfYear(arriveAlice) > dayOfYear(arriveBob)
        ? dayOfYear(arriveAlice)
        : dayOfYear(arriveBob);

    int end = dayOfYear(leaveAlice) < dayOfYear(leaveBob)
        ? dayOfYear(leaveAlice)
        : dayOfYear(leaveBob);

    return start > end ? 0 : end - start + 1;
}
