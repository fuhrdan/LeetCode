# 3886. Sum of Sortable Integers

**Difficulty:** Hard

For each divisor `k` of `n`, partition `nums` into fixed consecutive blocks of length `k`. Each block may only be cyclically rotated.

A candidate `k` works iff:

1. Every block can be rotated into non-decreasing order.
2. After doing so, the concatenated blocks are globally non-decreasing.

A block is cyclically sortable iff its circular sequence has at most one strict descent. For adjacent blocks, global order additionally requires:

```text
max(previous block) <= min(current block)
```

So for each divisor `k`, scan every block, count circular descents, and track block min/max.

## Complexity

If `d(n)` is the number of divisors of `n`:

- Time: `O(n * d(n) + sqrt(n))`
- Space: `O(1)` beyond the input and call stack

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3886. Sum of Sortable Integers](https://leetcode.com/problems/sum-of-sortable-integers/)
