# 1254. Number of Closed Islands

Use iterative flood fill in two passes:

1. Flood-fill every land cell (`0`) connected to the border and mark it as water (`1`).
2. Scan the interior. Every remaining `0` starts a closed island; count it and flood-fill it.

## Complexity
- Time: `O(rows * cols)`
- Space: `O(rows * cols)` worst case for the explicit stack

## Files
- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

[LeetCode 1254](https://leetcode.com/problems/number-of-closed-islands/)
