class Solution
{
    private int dayOfYear(String date)
    {
        int[] daysPerMonth =
        {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int month = (date.charAt(0) - '0') * 10 + (date.charAt(1) - '0');
        int day = (date.charAt(3) - '0') * 10 + (date.charAt(4) - '0');
        int retVal = day;

        for (int i = 0; i < month - 1; i++)
        {
            retVal += daysPerMonth[i];
        }

        return retVal;
    }

    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob)
    {
        int start = Math.max(dayOfYear(arriveAlice), dayOfYear(arriveBob));
        int end = Math.min(dayOfYear(leaveAlice), dayOfYear(leaveBob));

        return Math.max(0, end - start + 1);
    }
}
