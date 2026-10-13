# 3727. Maximum Alternating Sum of Squares

**Difficulty:** Medium

You are given an integer array `nums`. You may rearrange its elements in any order.

The alternating score is:

```text
arr[0]^2 - arr[1]^2 + arr[2]^2 - arr[3]^2 + ...
```

Return the maximum possible alternating score after rearranging the array.

## Key Observation

After squaring, the sign of the original number no longer matters.

There are:

- `ceil(n / 2)` positive-sign positions
- `floor(n / 2)` negative-sign positions

To maximize the score, assign the largest squared values to the positive positions and the smallest squared values to the negative positions.

## Approach

1. Square every value using 64-bit arithmetic.
2. Sort the squared values in ascending order.
3. Let `negativeCount = n / 2`.
4. Subtract the first `negativeCount` squares.
5. Add the remaining squares.

## Example

For:

```text
nums = [1, 2, 3]
```

Squares:

```text
1, 4, 9
```

There is one negative position and two positive positions:

```text
-1 + 4 + 9 = 12
```

## Complexity

- **Time:** `O(n log n)`
- **Space:** `O(n)`

## Files

- `solution.c` — C implementation
- `solution.cpp` — C++ implementation
- `Solution.java` — Java implementation
- `solution.rs` — Rust implementation

## LeetCode

[3727. Maximum Alternating Sum of Squares](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)
