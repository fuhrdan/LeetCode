# 2897. Apply Operations on Array to Maximize Sum of Squares

**Difficulty:** Hard

You are given an integer array `nums` and an integer `k`.

You may repeatedly choose two indices `i` and `j` and replace:

```text
nums[i] = nums[i] AND nums[j]
nums[j] = nums[i] OR nums[j]
```

After any number of operations, choose exactly `k` elements and maximize the sum of their squares.

Return the answer modulo `1_000_000_007`.

## Key Observation

For each bit position, the AND/OR operation preserves the total number of set bits across the array.

So we only need to count how many times each bit appears and redistribute those bits to make the chosen numbers as large as possible.

Because squaring is convex, concentrating set bits into the same numbers maximizes the total sum of squares.

## Greedy Construction

1. Count how many numbers contain each bit.
2. Construct `k` values.
3. For each constructed value, take every bit whose remaining count is positive.
4. Decrement that bit's count after using it.
5. Add the square of the constructed value to the answer.

## Complexity

There are only 31 relevant bit positions for `nums[i] <= 10^9`.

- **Time:** `O(31 * (n + k))`
- **Space:** `O(31)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[2897. Apply Operations on Array to Maximize Sum of Squares](https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/)
