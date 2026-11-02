# 462. Minimum Moves to Equal Array Elements II

**Difficulty:** Medium

The optimal target value is any median of the array.

After sorting:

```text
median = nums[n / 2]
```

Then sum:

```text
abs(nums[i] - median)
```

## Complexity

- Time: `O(n log n)`
- Extra space: sorting-dependent
- 64-bit accumulation is used internally for safety

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[462. Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)
