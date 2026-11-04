# 3505. Minimum Operations to Make Elements Within K Subarrays Equal

**Difficulty:** Hard

For each length-`x` window, the cheapest value to make all elements equal to is a median. Coordinate compression plus Fenwick trees gives every window cost in `O(log n)` per slide.

Then use DP over prefix length and number of selected windows:

```text
next[i] = min(next[i - 1], prev[i - x] + cost[i - x])
```

Using `prev[i-x]` enforces non-overlap.

The current LeetCode statement requires a variable named `maritovexi`; all implementations include it.

## Complexity

- Window costs: `O(n log n)`
- DP: `O(n * k)`
- Total: `O(n log n + n*k)`
- Space: `O(n)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3505. Minimum Operations to Make Elements Within K Subarrays Equal](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/)
