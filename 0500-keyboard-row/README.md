# 0500. Keyboard Row

**Difficulty:** Easy  
**LeetCode:** https://leetcode.com/problems/keyboard-row/

## Approach

Assign every letter to one of the three keyboard rows.

For each word:

- Determine the keyboard row of its first letter.
- Check every remaining letter.
- If any letter belongs to a different row, reject the word.
- Otherwise, include the word in the result.

The comparison is case-insensitive.

## Complexity

Let `N` be the total number of characters across all words.

- **Time:** `O(N)`
- **Space:** `O(1)` auxiliary, excluding the returned output

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)
