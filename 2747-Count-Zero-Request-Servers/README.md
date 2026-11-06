# 2747. Count Zero Request Servers

**Difficulty:** Medium

Sort the logs by time and sort queries by query time while keeping each query's original index.

Maintain a sliding window of logs whose timestamps are inside:

```text
[query - x, query]
```

Track how many requests each server has inside the current window and how many distinct servers are active.

For each query:

```text
zeroRequestServers = n - activeServers
```

## Complexity

- Time: `O(logs.length log logs.length + queries.length log queries.length)`
- Space: `O(n + queries.length)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[2747. Count Zero Request Servers](https://leetcode.com/problems/count-zero-request-servers/)
