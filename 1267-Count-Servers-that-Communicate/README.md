# 1267. Count Servers that Communicate

**Difficulty:** Medium

A server can communicate if there is at least one other server in the same row or the same column.

## Approach

Use two passes.

### First pass
Count the number of servers in every row and every column.

```text
rowCount[i]
colCount[j]
```

### Second pass
For every server at `(i, j)`, it communicates if:

```text
rowCount[i] > 1 || colCount[j] > 1
```

## Complexity
- **Time:** `O(m * n)`
- **Space:** `O(m + n)`

## Files
- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode
[1267. Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate/)
