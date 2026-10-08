# 1021. Remove Outermost Parentheses

**Difficulty:** Easy

Given a valid parentheses string `s`, remove the outermost parentheses from every primitive component in its primitive decomposition.

## Examples

```text
Input:  s = "(()())(())"
Output: "()()()"
```

```text
Input:  s = "(()())(())(()(()))"
Output: "()()()()(())"
```

```text
Input:  s = "()()"
Output: ""
```

## Approach

Track the current nesting `depth`.

For `'('`:
- Append it only when `depth > 0`.
- Then increment `depth`.

For `')'`:
- First decrement `depth`.
- Append it only when `depth > 0`.

This skips the first opening and last closing parenthesis of each primitive component.

## Complexity

- **Time:** `O(n)`
- **Extra working space:** `O(1)`
- **Output space:** `O(n)`

## Files

- `solution.c` — C implementation
- `solution.cpp` — C++ implementation
- `Solution.java` — Java implementation
- `solution.rs` — Rust implementation

## LeetCode

[1021. Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/)
