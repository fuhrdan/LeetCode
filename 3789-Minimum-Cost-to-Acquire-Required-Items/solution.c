long long minimumCost(
    int cost1,
    int cost2,
    int costBoth,
    int need1,
    int need2)
{
    long long common =
        need1 < need2 ? need1 : need2;

    long long remaining1 =
        (long long)need1 - common;

    long long remaining2 =
        (long long)need2 - common;

    long long pairedCost =
        costBoth < cost1 + (long long)cost2
        ? costBoth
        : cost1 + (long long)cost2;

    long long type1Cost =
        cost1 < costBoth ? cost1 : costBoth;

    long long type2Cost =
        cost2 < costBoth ? cost2 : costBoth;

    return common * pairedCost
        + remaining1 * type1Cost
        + remaining2 * type2Cost;
}
