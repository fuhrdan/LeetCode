# 9. Palindrome Number

**Difficulty:** Easy  
**LeetCode:** [Palindrome Number](https://leetcode.com/problems/palindrome-number/)

## Problem

Given an integer `x`, return `true` if `x` is a palindrome and `false` otherwise.

A palindrome reads the same from left to right and from right to left.

## Examples

### Example 1

```text
Input: x = 121
Output: true
```

Explanation:

```text
121
```

reads the same in both directions.

### Example 2

```text
Input: x = -121
Output: false
```

Explanation:

From left to right:

```text
-121
```

From right to left:

```text
121-
```

Therefore, a negative number cannot be a palindrome.

### Example 3

```text
Input: x = 10
Output: false
```

Reversing the digits would produce:

```text
01
```

which is not equal to `10`.

## Constraints

```text
-2^31 <= x <= 2^31 - 1
```

## Approach

Instead of converting the number to a string or reversing the entire integer, reverse only the second half of the number.

This avoids potential integer overflow and uses constant extra space.

First, eliminate two cases that cannot be palindromes:

1. Negative numbers are never palindromes because of the `-` sign.
2. Any non-zero number ending in `0` cannot be a palindrome because its first digit cannot also be `0`.

Then repeatedly move the last digit of `x` into `reversedHalf`:

```c
reversedHalf = reversedHalf * 10 + x % 10;
x /= 10;
```

Continue until `reversedHalf` is greater than or equal to the remaining portion of `x`.

For an even number of digits, the two halves should be equal:

```c
x == reversedHalf
```

For an odd number of digits, the middle digit can be ignored:

```c
x == reversedHalf / 10
```

For example:

```text
1221

x            = 12
reversedHalf = 12
```

The two halves match, so the number is a palindrome.

For:

```text
121
```

the final values are:

```text
x            = 1
reversedHalf = 12
```

Removing the middle digit gives:

```text
12 / 10 = 1
```

so the number is also a palindrome.

## C Solution

```c
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int reversedHalf = 0;

    while (x > reversedHalf)
    {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    return x == reversedHalf ||
           x == reversedHalf / 10;
}
```

## Complexity

- **Time:** `O(log10(x))`
- **Space:** `O(1)`

Only half of the digits need to be reversed, and no additional data structure is required.