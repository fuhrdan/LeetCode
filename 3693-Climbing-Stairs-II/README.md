# 3693. Climbing Stairs II

**Difficulty:** Medium

You start at step `0` and want to reach step `n`.

From step `i`, you may jump to:

```text
i + 1
i + 2
i + 3
```

Jumping from `i` to `j` costs:

```text
costs[j] + (j - i)^2
```

In code, `costs` is 0-indexed, so the cost of landing on step `i` is `costs[i - 1]`.

## Dynamic Programming

Let:

```text
dp[i] = minimum total cost to reach step i
```

Then:

```text
dp[i] =
    costs[i - 1]
    + min(
        dp[i - 1] + 1,
        dp[i - 2] + 4,
        dp[i - 3] + 9
      )
```

using only valid predecessor steps.

Because only the previous three DP values are needed, the implementations use a four-slot circular buffer.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3693. Climbing Stairs II](https://leetcode.com/problems/climbing-stairs-ii/)
