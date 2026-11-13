# 3420. Count Non-Decreasing Subarrays After K Operations

**Difficulty:** Hard

For any subarray, the minimum number of increments needed to make it non-decreasing is obtained by raising each element to the maximum value seen so far from the left.

This solution:

1. Computes each index's next strictly greater element.
2. Builds binary-lifting tables over those prefix-maximum change points.
3. Answers the adjustment cost of any subarray in `O(log n)`.
4. Binary-searches the farthest valid right endpoint for every left endpoint.

## Complexity

- Preprocessing: `O(n log n)`
- Cost query: `O(log n)`
- Binary search per left endpoint: `O(log n)` queries
- Total: `O(n log^2 n)`
- Space: `O(n log n)`

All costs and the final answer use 64-bit integers.

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3420. Count Non-Decreasing Subarrays After K Operations](https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/)
