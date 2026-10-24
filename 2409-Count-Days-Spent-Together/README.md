# 2409. Count Days Spent Together

**Difficulty:** Easy

Convert each `MM-DD` date to a day-of-year value, then compute the inclusive overlap.

```text
start = max(aliceStart, bobStart)
end   = min(aliceEnd, bobEnd)
answer = max(0, end - start + 1)
```

## Complexity

- Time: `O(1)`
- Space: `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[2409. Count Days Spent Together](https://leetcode.com/problems/count-days-spent-together/)
