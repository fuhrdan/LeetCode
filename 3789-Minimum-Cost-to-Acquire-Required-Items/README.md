# 3789. Minimum Cost to Acquire Required Items

**Difficulty:** Medium

Let:

```text
common = min(need1, need2)
```

For the common demand, each unit can be satisfied by either one type-3 item or one type-1 plus one type-2 item:

```text
pairedCost = min(costBoth, cost1 + cost2)
```

For any remaining type-1-only demand:

```text
type1Cost = min(cost1, costBoth)
```

For any remaining type-2-only demand:

```text
type2Cost = min(cost2, costBoth)
```

Therefore:

```text
answer =
    common * pairedCost
    + (need1 - common) * type1Cost
    + (need2 - common) * type2Cost
```

## Complexity

- Time: `O(1)`
- Space: `O(1)`

Use 64-bit arithmetic because needs can be as large as `10^9`.

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3789. Minimum Cost to Acquire Required Items](https://leetcode.com/problems/minimum-cost-to-acquire-required-items/)
