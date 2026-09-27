# 3. Longest Substring Without Repeating Characters

**Difficulty:** Medium  
**LeetCode:** [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Problem

Given a string `s`, find the length of the longest substring without repeating characters.

## Examples

### Example 1

```text
Input: s = "abcabcbb"
Output: 3
```

Explanation:

The answer is `"abc"`, with a length of `3`.

Other valid substrings of length `3` include `"bca"` and `"cab"`.

### Example 2

```text
Input: s = "bbbbb"
Output: 1
```

Explanation:

The longest substring without repeating characters is `"b"`.

### Example 3

```text
Input: s = "pwwkew"
Output: 3
```

Explanation:

The answer is `"wke"`, with a length of `3`.

`"pwke"` is not valid because it is a subsequence rather than a contiguous substring.

## Constraints

- `0 <= s.length <= 100000`
- `s` consists of English letters, digits, symbols, and spaces.

## Approach

Use a sliding window to track the current substring containing no duplicate characters.

An array stores the most recent index where each character appeared.

As the right side of the window moves through the string:

1. Check whether the current character has already appeared inside the current window.
2. If it has, move the left side of the window to one position after the previous occurrence.
3. Update the character's most recent position.
4. Track the maximum window length encountered.

This allows the string to be processed in a single pass.