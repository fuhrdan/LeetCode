# 3882. Minimum XOR Path in a Grid

**Difficulty:** Medium

Use dynamic programming over reachable XOR states.

Because every cell value is in `0..1023`, every path XOR is also in `0..1023`.

Define:

```text
dp[i][j][x] = whether cell (i,j) can be reached with XOR x
```

For current cell value `v`, a state `x` is reachable if `x ^ v` was reachable from the cell above or the cell to the left.

The live LeetCode version uses the method name `minCost` and also requests a variable named `molqaviren`; the implementations include it.

## Complexity

- Time: `O(m * n * 1024)`
- Space: `O(m * n * 1024)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3882. Minimum XOR Path in a Grid](https://leetcode.com/problems/minimum-xor-path-in-a-grid/)
