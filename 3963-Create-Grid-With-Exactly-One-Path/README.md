# 3963. Create Grid With Exactly One Path

**Difficulty:** Easy

Construct any `m x n` grid using `'.'` for free cells and `'#'` for obstacles such that there is exactly one valid path from `(0, 0)` to `(m - 1, n - 1)` using only right and down moves.

## Construction

Open:

- the entire top row
- the entire last column

Block every other cell.

The only possible valid path is therefore:

```text
(0,0) -> ... -> (0,n-1) -> ... -> (m-1,n-1)
```

No alternate route exists because every off-path cell is blocked.

## Complexity

- **Time:** `O(m * n)`
- **Space:** `O(m * n)` for the returned grid

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3963. Create Grid With Exactly One Path](https://leetcode.com/problems/create-grid-with-exactly-one-path/)
