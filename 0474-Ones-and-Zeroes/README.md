# 474. Ones and Zeroes

**Difficulty:** Medium

This is a 0/1 knapsack problem with two capacities:

- at most `m` zeroes
- at most `n` ones

For each string, count its zeroes and ones, then update a 2D DP table backwards so each string is used at most once.

## DP

```text
dp[z][o] = maximum number of strings using at most z zeroes and o ones
```

For a string with `zeroes` zeroes and `ones` ones:

```text
dp[z][o] = max(
    dp[z][o],
    dp[z - zeroes][o - ones] + 1
)
```

Iterate `z` and `o` backwards.

## Complexity

- Time: `O(strs.length * m * n)`
- Space: `O(m * n)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)
