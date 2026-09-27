# 5. Longest Palindromic Substring

**Difficulty:** Medium  
**LeetCode:** [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

## Problem

Given a string `s`, return the longest palindromic substring in `s`.

A palindrome is a string that reads the same forward and backward.

## Examples

### Example 1

```text
Input: s = "babad"
Output: "bab"
```

Explanation:

```text
"bab"
```

is a palindrome with length `3`.

`"aba"` is also a valid answer.

### Example 2

```text
Input: s = "cbbd"
Output: "bb"
```

Explanation:

The longest palindromic substring is:

```text
"bb"
```

## Constraints

- `1 <= s.length <= 1000`
- `s` consists only of digits and English letters.

## Approach

Use the **expand around center** technique.

Every palindrome has a center.

An odd-length palindrome has a single character as its center:

```text
b a b
  ^
```

An even-length palindrome has a center between two characters:

```text
b b
 ^
```

For every position in the string:

1. Treat the current character as the center of an odd-length palindrome.
2. Expand outward while the characters on both sides match.
3. Treat the gap between the current character and the next character as the center of an even-length palindrome.
4. Expand outward again.
5. Track the starting position and length of the longest palindrome found.

After processing all possible centers, allocate a new string containing the longest palindrome.

## C Solution

```c
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    int length = strlen(s);

    if (length <= 1)
    {
        char* retVal = malloc((length + 1) * sizeof(char));

        if (retVal == NULL)
        {
            return NULL;
        }

        strcpy(retVal, s);
        return retVal;
    }

    int bestStart = 0;
    int bestLength = 1;

    for (int center = 0; center < length; center++)
    {
        int left = center;
        int right = center;

        while (left >= 0 &&
               right < length &&
               s[left] == s[right])
        {
            int currentLength = right - left + 1;

            if (currentLength > bestLength)
            {
                bestStart = left;
                bestLength = currentLength;
            }

            left--;
            right++;
        }

        left = center;
        right = center + 1;

        while (left >= 0 &&
               right < length &&
               s[left] == s[right])
        {
            int currentLength = right - left + 1;

            if (currentLength > bestLength)
            {
                bestStart = left;
                bestLength = currentLength;
            }

            left--;
            right++;
        }
    }

    char* retVal = malloc((bestLength + 1) * sizeof(char));

    if (retVal == NULL)
    {
        return NULL;
    }

    memcpy(retVal, s + bestStart, bestLength);
    retVal[bestLength] = '\0';

    return retVal;
}
```

## Complexity

- **Time:** `O(n²)`
- **Space:** `O(1)` auxiliary space

The returned palindrome requires `O(n)` space in the worst case, but the algorithm itself uses only constant extra working space.