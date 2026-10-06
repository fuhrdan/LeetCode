# 921. Minimum Add to Make Parentheses Valid

**Difficulty:** Medium

Given a parentheses string `s`, return the minimum number of parentheses that must be inserted to make the string valid.

## Examples

```text
Input:  s = "())"
Output: 1
```

```text
Input:  s = "((("
Output: 3
```

## Approach

Track two values while scanning from left to right:

- `balance` — unmatched opening parentheses `'('`
- `needed` — opening parentheses that must be inserted because a `')'` appeared without a matching `'('`

For each character:

- If it is `'('`, increment `balance`.
- If it is `')'` and `balance > 0`, decrement `balance`.
- Otherwise, increment `needed`.

At the end, each unmatched `'('` needs one closing parenthesis, so:

```text
answer = needed + balance
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Files

- `solution.c` — C implementation
- `solution.cpp` — C++ implementation
- `Solution.java` — Java implementation
- `solution.rs` — Rust implementation

## LeetCode

[921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
