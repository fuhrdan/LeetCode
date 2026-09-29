# 2267. Check if There Is a Valid Parentheses String Path

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/

## Approach

Use dynamic programming over the grid.

For each cell, track every possible unmatched opening-parenthesis balance that can reach that cell.

- `(` increases the balance by 1.
- `)` decreases the balance by 1.
- A balance may never become negative.
- At the bottom-right cell, balance must be exactly 0.

A valid parentheses string must also have even total length, so reject immediately when `(rows + cols - 1)` is odd.

## Complexity

Let `L = rows + cols`.

- **Time:** `O(rows × cols × L)`
- **Space:** `O(cols × L)` with rolling DP

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)
