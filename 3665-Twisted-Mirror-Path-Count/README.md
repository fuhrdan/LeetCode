# 3665. Twisted Mirror Path Count

**Difficulty:** Medium

Use row-by-row dynamic programming.

Maintain:
- `down[col]`: paths arriving from above
- `left`: paths arriving from the left

For an empty cell:

```text
total = left + down[col]
left = total
down[col] = total
```

For a mirror:

```text
swap(left, down[col])
```

This models:
- right into mirror -> down
- down into mirror -> right

Initialize `down[0] = 1`.

## Complexity

- Time: `O(m * n)`
- Space: `O(n)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3665. Twisted Mirror Path Count](https://leetcode.com/problems/twisted-mirror-path-count/)
