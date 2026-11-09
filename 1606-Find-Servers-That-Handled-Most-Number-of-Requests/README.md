# 1606. Find Servers That Handled Most Number of Requests

**Difficulty:** Hard

Use a min-heap for busy servers and a Fenwick tree to represent available server IDs.

For request `i`, first release every server with `freeTime <= arrival[i]`. Then choose the first available server with ID at least `i % k`; if none exists, wrap to the first available server.

The Fenwick tree supports prefix counts and k-th available-server lookup in `O(log k)`.

## Complexity

- Time: `O((k + m) log k)`
- Space: `O(k)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[1606. Find Servers That Handled Most Number of Requests](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)
