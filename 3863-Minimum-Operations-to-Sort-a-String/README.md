# 3863. Minimum Operations to Sort a String

**Difficulty:** Medium

You may sort any proper substring of `s` in one operation.

## O(n) Case Analysis

Let `mn` be the minimum character and `mx` the maximum character.

- Already sorted -> `0`
- Unsorted length 2 -> `-1`
- `s[0] == mn` or `s[n - 1] == mx` -> `1`
- Some interior character is `mn` or `mx` -> `2`
- Otherwise -> `3`

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3863. Minimum Operations to Sort a String](https://leetcode.com/problems/minimum-operations-to-sort-a-string/)
