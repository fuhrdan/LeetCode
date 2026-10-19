# 2089. Find Target Indices After Sorting Array

**Difficulty:** Easy

Given `nums` and `target`, return the indices where `target` would appear after sorting `nums` in non-decreasing order.

## O(n) approach

We do not need to sort.

Count:

```text
less  = number of values < target
equal = number of values == target
```

After sorting, all targets occupy the contiguous range:

```text
less ... less + equal - 1
```

## Complexity

- Time: `O(n)`
- Extra space: `O(1)` excluding the result

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[2089. Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/)
