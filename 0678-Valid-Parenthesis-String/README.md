# 678. Valid Parenthesis String

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/valid-parenthesis-string/

## Problem

Given a string `s` containing only `'('`, `')'`, and `'*'`, return `true` if the string can be valid.

The `'*'` character may represent:

- `'('`
- `')'`
- an empty string

A valid parenthesis string must have matching parentheses in the correct order.

### Examples

```text
Input: s = "()"
Output: true

Input: s = "(*)"
Output: true

Input: s = "(*))"
Output: true

Input: s = "("
Output: false
```

## Approach — Greedy Range of Possible Open Parentheses

Instead of deciding immediately what every `'*'` means, keep a range describing how many unmatched opening parentheses are possible after reading each character.

- `low` = minimum possible number of unmatched `'('`
- `high` = maximum possible number of unmatched `'('`

For each character:

- `'('` increases both `low` and `high`.
- `')'` decreases both.
- `'*'` can act as `')'`, empty, or `'('`, so it decreases `low` and increases `high`.

`low` is never allowed below zero because we can choose a different interpretation of earlier `'*'` characters when necessary.

If `high` ever becomes negative, there are more required closing parentheses than could possibly be matched, so the string is invalid.

At the end, the string is valid exactly when `low == 0`.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Files

- `solution.c` — C implementation
- `solution.cpp` — C++ implementation
- `solution.rs` — Rust implementation
- `Solution.java` — Java implementation

## C

```c
bool checkValidString(char* s);
```

## C++

```cpp
class Solution {
public:
    bool checkValidString(string s);
};
```

## Rust

```rust
impl Solution {
    pub fn check_valid_string(s: String) -> bool;
}
```

## Java

```java
class Solution {
    public boolean checkValidString(String s);
}
```
