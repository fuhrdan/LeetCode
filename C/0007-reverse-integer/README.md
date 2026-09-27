# 7. Reverse Integer

**Difficulty:** Medium  
**LeetCode:** [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

## Problem

Given a signed 32-bit integer `x`, return `x` with its digits reversed.

If reversing `x` causes the result to fall outside the signed 32-bit integer range:

```text
[-2^31, 2^31 - 1]
```

return `0`.

The solution must not use 64-bit integers.

## Examples

### Example 1

```text
Input: x = 123
Output: 321
```

### Example 2

```text
Input: x = -123
Output: -321
```

### Example 3

```text
Input: x = 120
Output: 21
```

The leading zero in the reversed representation is discarded automatically.

## Constraints

```text
-2^31 <= x <= 2^31 - 1
```

## Approach

Repeatedly remove the last digit from `x` and append it to the reversed result.

The last digit is obtained using:

```c
digit = x % 10;
```

Then remove that digit from `x`:

```c
x /= 10;
```

The reversed value would normally be updated using:

```c
retVal = retVal * 10 + digit;
```

However, this multiplication could overflow a signed 32-bit integer.

Because the problem does not allow using a 64-bit integer to detect overflow afterward, overflow must be checked before performing the multiplication.

For a positive result, overflow occurs if:

```text
retVal > INT_MAX / 10
```

or if:

```text
retVal == INT_MAX / 10
```

and the next digit is greater than `7`.

For a negative result, underflow occurs if:

```text
retVal < INT_MIN / 10
```

or if:

```text
retVal == INT_MIN / 10
```

and the next digit is less than `-8`.

These limits come from:

```text
INT_MAX =  2147483647
INT_MIN = -2147483648
```

## C Solution

```c
#include <limits.h>

int reverse(int x)
{
    int retVal = 0;

    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;

        if (retVal > INT_MAX / 10 ||
            (retVal == INT_MAX / 10 && digit > 7))
        {
            return 0;
        }

        if (retVal < INT_MIN / 10 ||
            (retVal == INT_MIN / 10 && digit < -8))
        {
            return 0;
        }

        retVal = retVal * 10 + digit;
    }

    return retVal;
}
```

## Complexity

- **Time:** `O(log10 |x|)`
- **Space:** `O(1)`

Only a few integer variables are used regardless of the size of the input.