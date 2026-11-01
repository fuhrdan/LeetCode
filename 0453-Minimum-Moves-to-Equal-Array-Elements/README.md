# 453. Minimum Moves to Equal Array Elements

**Difficulty:** Medium

In one move, incrementing `n - 1` elements is equivalent to decrementing the one untouched element by `1` relative to the others.

Therefore the optimal target is the minimum element:

```text
answer = sum(nums[i] - min(nums))
```

## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Files
- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

[LeetCode 453](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)
