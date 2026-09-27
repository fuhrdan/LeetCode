# 0269. Alien Dictionary

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/alien-dictionary/

## Approach

Build precedence edges from the first differing character of adjacent words, then topologically sort the characters.

## Complexity

- **Time:** `O(total characters + edges)`
- **Space:** `O(1) alphabet-sized graph`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
