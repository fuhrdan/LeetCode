# 3644. Maximum K to Sort a Permutation

**Difficulty:** Medium

You are given a permutation `nums` of the integers `0..n-1`.

You may swap two values only when:

```text
nums[i] AND nums[j] == k
```

Return the maximum value of `k` that still allows the permutation to be sorted. If the array is already sorted, return `0`.

## Key Observation

Only misplaced values matter.

For any bit to be present in a valid `k`, that bit must be present in every value that needs to move. Therefore the largest possible `k` is the bitwise AND of all misplaced values:

```text
answer = AND(nums[i]) for every i where nums[i] != i
```

If there are no misplaced values, the permutation is already sorted and the answer is `0`.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3644. Maximum K to Sort a Permutation](https://leetcode.com/problems/maximum-k-to-sort-a-permutation/)
