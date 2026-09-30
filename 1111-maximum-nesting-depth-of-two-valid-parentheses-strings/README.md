# 1111. Maximum Nesting Depth of Two Valid Parentheses Strings

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

## Approach

Split the parentheses between groups `A` and `B` by alternating assignments according to the current nesting depth.

For each character:

- On `(`, assign it using the current depth parity, then increase the depth.
- On `)`, decrease the depth first, then assign it using that depth parity.

This distributes nested levels as evenly as possible between the two resulting valid parentheses strings, minimizing the maximum nesting depth of either group.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)` for the returned array

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)
