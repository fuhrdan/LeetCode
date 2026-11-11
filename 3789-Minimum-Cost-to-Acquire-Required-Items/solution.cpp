class Solution
{
public:
    long long minimumCost(
        int cost1,
        int cost2,
        int costBoth,
        int need1,
        int need2)
    {
        long long common = min(need1, need2);

        long long remaining1 =
            static_cast<long long>(need1) - common;

        long long remaining2 =
            static_cast<long long>(need2) - common;

        long long pairedCost =
            min(
                static_cast<long long>(costBoth),
                static_cast<long long>(cost1) + cost2);

        long long type1Cost =
            min(
                static_cast<long long>(cost1),
                static_cast<long long>(costBoth));

        long long type2Cost =
            min(
                static_cast<long long>(cost2),
                static_cast<long long>(costBoth));

        return common * pairedCost
            + remaining1 * type1Cost
            + remaining2 * type2Cost;
    }
};
