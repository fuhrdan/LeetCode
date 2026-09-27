# 0353. Design Snake Game

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/design-snake-game/

## Approach

Track the snake body in a deque plus occupied-cell set; move the head, optionally remove the tail, and detect wall/body collisions.

## Complexity

- **Time:** `O(1) average per move`
- **Space:** `O(board area)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
