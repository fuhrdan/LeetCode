# 3723. Maximize Sum of Squares of Digits

**Difficulty:** Medium

Construct a positive integer with exactly `num` digits and digit sum exactly `sum`, maximizing the sum of squared digits. If several solutions have the same score, return the numerically largest one. If impossible, return an empty string.

## Greedy idea

For a fixed digit sum, convexity means the square-sum is maximized by concentrating value into the largest digits possible:

```text
9, 9, ..., remainder, 0, 0, ...
```

where:

```text
fullNines = sum / 9
remainder = sum % 9
```

This arrangement is already descending, so it is also the largest numerical value among maximum-score solutions.

A solution exists iff:

```text
sum <= 9 * num
```

## Complexity

- Time: `O(num)`
- Space: `O(num)` for the returned string

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3723. Maximize Sum of Squares of Digits](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/)
