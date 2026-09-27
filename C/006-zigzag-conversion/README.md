# 6. Zigzag Conversion

**Difficulty:** Medium  
**LeetCode:** [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)

## Problem

The string `"PAYPALISHIRING"` can be written in a zigzag pattern across a specified number of rows.

For example, with `3` rows:

```text
P   A   H   N
A P L S I I G
Y   I   R
```

Reading the rows from left to right produces:

```text
PAHNAPLSIIGYIR
```

Given a string `s` and an integer `numRows`, return the zigzag-converted string.

## Examples

### Example 1

```text
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```

The zigzag pattern is:

```text
P   A   H   N
A P L S I I G
Y   I   R
```

### Example 2

```text
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
```

The zigzag pattern is:

```text
P     I     N
A   L S   I G
Y A   H R
P     I
```

### Example 3

```text
Input: s = "A", numRows = 1
Output: "A"
```

## Constraints

- `1 <= s.length <= 1000`
- `s` consists of English letters, `','`, and `'.'`
- `1 <= numRows <= 1000`

## Approach

The zigzag pattern repeats in cycles.

For a given number of rows, the cycle length is:

```text
cycleLength = 2 * numRows - 2
```

For example, when:

```text
numRows = 4
```

the cycle length is:

```text
2 * 4 - 2 = 6
```

Instead of constructing a two-dimensional zigzag grid, process the string row by row.

For each row:

1. Take characters separated by one full cycle.
2. For middle rows, also include the diagonal character within the same cycle.
3. Append each selected character directly to the result string.

The first and last rows contain only one character per cycle, while the middle rows can contain two.

## C Solution

```c
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    int length = strlen(s);

    if (numRows == 1 || numRows >= length)
    {
        char* retVal = malloc((length + 1) * sizeof(char));

        if (retVal == NULL)
        {
            return NULL;
        }

        strcpy(retVal, s);
        return retVal;
    }

    char* retVal = malloc((length + 1) * sizeof(char));

    if (retVal == NULL)
    {
        return NULL;
    }

    int cycleLength = 2 * numRows - 2;
    int index = 0;

    for (int row = 0; row < numRows; row++)
    {
        for (int i = row; i < length; i += cycleLength)
        {
            retVal[index++] = s[i];

            int diagonal = i + cycleLength - 2 * row;

            if (row != 0 &&
                row != numRows - 1 &&
                diagonal < length)
            {
                retVal[index++] = s[diagonal];
            }
        }
    }

    retVal[index] = '\0';

    return retVal;
}
```

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

The result string requires `O(n)` space. The algorithm itself uses only constant additional working space.