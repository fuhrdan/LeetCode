class Solution
{
    public long minimumCost(
        int cost1,
        int cost2,
        int costBoth,
        int need1,
        int need2)
    {
        long common = Math.min(need1, need2);

        long remaining1 =
            (long)need1 - common;

        long remaining2 =
            (long)need2 - common;

        long pairedCost =
            Math.min(
                (long)costBoth,
                (long)cost1 + cost2);

        long type1Cost =
            Math.min(
                (long)cost1,
                (long)costBoth);

        long type2Cost =
            Math.min(
                (long)cost2,
                (long)costBoth);

        return common * pairedCost
            + remaining1 * type1Cost
            + remaining2 * type2Cost;
    }
}
