# 2778. Sum of Squares of Special Elements

**Difficulty:** Easy

You are given a **1-indexed** integer array `nums` of length `n`.

An element `nums[i]` is special when its 1-based index `i` divides `n`.

## Approach

The array is 0-indexed in code, so for position `i`, the problem's index is:

```text
index = i + 1
```

If:

```text
n % index == 0
```

then add:

```text
nums[i] * nums[i]
```

to the result.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[2778. Sum of Squares of Special Elements](https://leetcode.com/problems/sum-of-squares-of-special-elements/)
