# 1385. Find the Distance Value Between Two Arrays

**Difficulty:** Easy

The distance value is the number of elements `arr1[i]` such that there is no element `arr2[j]` satisfying:

```text
|arr1[i] - arr2[j]| <= d
```

## Approach

For each value in `arr1`, scan every value in `arr2`. If any value in `arr2` is within distance `d`, that `arr1` value does not count. Otherwise, increment the answer.

## Complexity

- **Time:** `O(arr1.length * arr2.length)`
- **Space:** `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[1385. Find the Distance Value Between Two Arrays](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/)
