# 856. Score of Parentheses

**Difficulty:** Medium

Given a balanced parentheses string `s`, return the score of the string.

## Rules

- `"()"` has score `1`
- `AB` has score `A + B`
- `(A)` has score `2 * A`

## Approach

Use the current nesting depth.

Whenever we encounter a primitive pair `"()"`, its contribution is:

```text
2^depth
```

where `depth` is the number of surrounding pairs after the closing parenthesis is processed.

For example, in `(())`, the inner `()` is nested once, so it contributes `2`.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Files

- `solution.c` — C implementation
- `solution.cpp` — C++ implementation
- `Solution.java` — Java implementation
- `solution.rs` — Rust implementation

## LeetCode

[856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/)
