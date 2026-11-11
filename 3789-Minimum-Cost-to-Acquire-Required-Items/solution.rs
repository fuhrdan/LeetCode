impl Solution
{
    pub fn minimum_cost(
        cost1: i32,
        cost2: i32,
        cost_both: i32,
        need1: i32,
        need2: i32) -> i64
    {
        let common = need1.min(need2) as i64;

        let remaining1 =
            need1 as i64 - common;

        let remaining2 =
            need2 as i64 - common;

        let paired_cost =
            (cost_both as i64)
                .min(cost1 as i64 + cost2 as i64);

        let type1_cost =
            (cost1 as i64)
                .min(cost_both as i64);

        let type2_cost =
            (cost2 as i64)
                .min(cost_both as i64);

        common * paired_cost
            + remaining1 * type1_cost
            + remaining2 * type2_cost
    }
}
