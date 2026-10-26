# 3619. Count Islands With Total Value Divisible by K

**Difficulty:** Medium

Scan the grid and flood-fill each 4-directionally connected component of positive cells.

For each island:
1. Sum all cell values using 64-bit arithmetic.
2. Mark visited cells as `0`.
3. Count the island if `sum % k == 0`.

## Complexity

- Time: `O(m * n)`
- Space: `O(m * n)` worst case for the iterative stack

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3619. Count Islands With Total Value Divisible by K](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/)
