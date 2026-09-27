# 3. Longest Substring Without Repeating Characters

**Difficulty:** Medium  
**Language:** Rust  
**LeetCode:** [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Problem

Given a string `s`, find the length of the longest substring without repeating characters.

A substring must consist of contiguous characters from the original string.

## Examples

### Example 1

```text
Input: s = "abcabcbb"
Output: 3
```

Explanation:

The longest substring without repeating characters has a length of `3`.

Examples include:

```text
"abc"
"bca"
"cab"
```

### Example 2

```text
Input: s = "bbbbb"
Output: 1
```

Explanation:

The longest substring without repeating characters is:

```text
"b"
```

### Example 3

```text
Input: s = "pwwkew"
Output: 3
```

Explanation:

One valid longest substring is:

```text
"wke"
```

`"pwke"` is not valid because it is a subsequence rather than a contiguous substring.

## Constraints

- `0 <= s.length <= 100000`
- `s` consists of English letters, digits, symbols, and spaces.

## Approach

Use a sliding window to keep track of the current substring containing no duplicate characters.

An array stores the most recent index where each character was found.

For each character:

1. Check whether it has already appeared inside the current window.
2. If it has, move the left side of the window to one position after the previous occurrence.
3. Update the character's most recent index.
4. Calculate the current window length.
5. Keep track of the maximum length found.

The left side of the window only moves forward, allowing the string to be processed in a single pass.

## Rust Solution

```rust
impl Solution
{
    pub fn length_of_longest_substring(s: String) -> i32
    {
        let mut last_seen = [-1; 256];
        let mut left: i32 = 0;
        let mut max_length: i32 = 0;

        for (right, byte) in s.bytes().enumerate()
        {
            let index = byte as usize;
            let right = right as i32;

            if last_seen[index] >= left
            {
                left = last_seen[index] + 1;
            }

            last_seen[index] = right;

            let current_length = right - left + 1;

            if current_length > max_length
            {
                max_length = current_length;
            }
        }

        max_length
    }
}
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

The algorithm processes each character once, and the lookup array has a fixed size of 256 entries.