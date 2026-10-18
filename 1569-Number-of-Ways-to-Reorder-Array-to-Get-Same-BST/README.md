# 1569. Number of Ways to Reorder Array to Get Same BST

**Difficulty:** Hard

Given a permutation `nums` of `1..n`, insert its values into a BST in order. Return the number of **other** reorderings that generate the exact same BST, modulo `1_000_000_007`.

## Core idea

The first value is the root.

All later values smaller than the root form the left-subtree insertion sequence; larger values form the right-subtree insertion sequence.

If the left side has `L` values and the right side has `R` values, then after fixing a valid ordering for each subtree, those two sequences can be interleaved in:

```text
C(L + R, L)
```

ways while preserving the internal order within each side.

So:

```text
ways(nums)
= C(L + R, L)
  * ways(left)
  * ways(right)
```

The problem asks for reorderings other than the original sequence, so return:

```text
ways(nums) - 1
```

## Combinations

Because `n <= 1000`, precompute Pascal's triangle modulo `1_000_000_007`.

## Complexity

- **Time:** `O(n^2)` worst case
- **Space:** `O(n^2)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[1569. Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)
