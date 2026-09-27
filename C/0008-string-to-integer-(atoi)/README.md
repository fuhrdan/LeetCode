# 8. String to Integer (atoi)

**Difficulty:** Medium  
**LeetCode:** [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

## Problem

Implement the `myAtoi` function, which converts a string into a signed 32-bit integer.

The conversion follows these rules:

1. Ignore leading whitespace.
2. Check for an optional `+` or `-` sign.
3. Read consecutive digits until a non-digit character or the end of the string is reached.
4. If no digits are read, return `0`.
5. If the value exceeds the signed 32-bit integer range, clamp it to the appropriate limit.

The valid range is:

```text
[-2^31, 2^31 - 1]
```

or:

```text
[-2147483648, 2147483647]
```

## Examples

### Example 1

```text
Input: s = "42"
Output: 42
```

### Example 2

```text
Input: s = "   -042"
Output: -42
```

Leading whitespace is ignored, the negative sign is detected, and the digits `042` are converted to `42`.

### Example 3

```text
Input: s = "1337c0d3"
Output: 1337
```

Reading stops when the first non-digit character, `c`, is encountered.

### Example 4

```text
Input: s = "0-1"
Output: 0
```

The digit `0` is read first. Conversion stops when `-` is encountered.

### Example 5

```text
Input: s = "words and 987"
Output: 0
```

The first character is not whitespace, a sign, or a digit, so no valid integer is read.

## Approach

Process the string from left to right.

### 1. Skip Leading Whitespace

Advance past any leading spaces:

```c
while (s[index] == ' ')
{
    index++;
}
```

### 2. Determine the Sign

Check whether the next character is `+` or `-`.

If neither is present, assume the number is positive.

### 3. Read Digits

Continue while the current character is between `'0'` and `'9'`.

Convert each character into its numeric value:

```c
int digit = s[index] - '0';
```

Then append it to the current number:

```c
retVal = retVal * 10 + digit;
```

### 4. Detect Overflow

Because the result must remain within a signed 32-bit integer, overflow is checked before multiplying by `10`.

For positive values:

```text
2147483647
```

The final digit cannot exceed `7`.

For negative values:

```text
-2147483648
```

The final magnitude can reach `8`.

If the value exceeds these limits, return either:

```c
INT_MAX
```

or:

```c
INT_MIN
```

## C Solution

```c
#include <limits.h>

int myAtoi(char* s)
{
    int index = 0;
    int sign = 1;
    int retVal = 0;

    while (s[index] == ' ')
    {
        index++;
    }

    if (s[index] == '-' || s[index] == '+')
    {
        if (s[index] == '-')
        {
            sign = -1;
        }

        index++;
    }

    while (s[index] >= '0' && s[index] <= '9')
    {
        int digit = s[index] - '0';

        if (sign == 1)
        {
            if (retVal > INT_MAX / 10 ||
                (retVal == INT_MAX / 10 && digit > 7))
            {
                return INT_MAX;
            }
        }
        else
        {
            if (retVal > INT_MAX / 10 ||
                (retVal == INT_MAX / 10 && digit > 8))
            {
                return INT_MIN;
            }
        }

        retVal = retVal * 10 + digit;
        index++;
    }

    return sign * retVal;
}
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

The string is processed once, and only a few integer variables are required.