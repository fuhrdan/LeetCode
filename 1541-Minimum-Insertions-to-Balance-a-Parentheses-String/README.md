# 1541. Minimum Insertions to Balance a Parentheses String

**Difficulty:** Medium

Given a parentheses string `s` containing only `'('` and `')'`, return the minimum number of insertions needed to make it balanced under the rule that every `'('` must be matched by **two consecutive** right parentheses `'))'`.

## Examples

```text
Input:  s = "(()))"
Output: 1
```

```text
Input:  s = "())"
Output: 0
```

```text
Input:  s = "))())("
Output: 3
```

## Approach

Track how many right parentheses are still required.

Let:

- `needed` = number of `')'` characters currently required
- `insertions` = number of characters inserted so far

For every `'('`:

- If `needed` is odd, insert one `')'` first to complete the previous pair.
- Then add `2` to `needed`, because the new `'('` requires `'))'`.

For every `')'`:

- Decrement `needed`.
- If `needed` becomes negative, this `')'` has no matching `'('`.
- Insert one `'('`, which leaves one additional `')'` still required.

At the end:

```text
answer = insertions + needed
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

[1541. Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)
