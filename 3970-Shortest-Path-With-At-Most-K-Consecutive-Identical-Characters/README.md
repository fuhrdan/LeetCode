# 3970. Shortest Path With At Most K Consecutive Identical Characters

**Difficulty:** Medium

Use Dijkstra on expanded states `(node, runLength)`, where `runLength` is the current number of consecutive nodes with the same label.

When traversing `u -> v`:
- if `labels[u] == labels[v]`, `nextRun = runLength + 1`
- otherwise, `nextRun = 1`
- skip transitions with `nextRun > k`

The live LeetCode version uses method name `shortestPath` and requests a variable named `mavorqeli`; all implementations include it.

## Complexity
- Time: `O((n*k + E*k) log(n*k))`
- Space: `O(n*k + E)`

## Files
- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

[LeetCode 3970](https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/)
