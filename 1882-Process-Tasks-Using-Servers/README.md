# 1882. Process Tasks Using Servers

**Difficulty:** Medium

Use two priority queues:

- Free servers ordered by `(weight, index)`
- Busy servers ordered by `(freeTime, weight, index)`

For each task:
1. Advance time to at least its arrival time.
2. Release all servers whose `freeTime <= currentTime`.
3. If no server is free, jump to the earliest busy server's release time and release every server available then.
4. Assign the task to the best free server.
5. Push that server into the busy queue with its new release time.

## Complexity

- Time: `O((n + m) log n)`
- Space: `O(n + m)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[1882. Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/)
