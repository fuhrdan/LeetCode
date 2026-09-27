# 10. Regular Expression Matching

**Difficulty:** Hard  
**LeetCode:** [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)

## Problem

Given an input string `s` and a pattern `p`, implement regular expression matching with support for:

- `.` which matches any single character
- `*` which matches zero or more occurrences of the preceding element

The match must cover the entire input string.

## Examples

### Example 1

```text
Input: s = "aa", p = "a"
Output: false
```

Explanation:

The pattern `"a"` matches only one character, so it does not match the entire string `"aa"`.

### Example 2

```text
Input: s = "aa", p = "a*"
Output: true
```

Explanation:

`*` means zero or more occurrences of the preceding element.

Therefore:

```text
a* -> aa
```

matches the entire input string.

### Example 3

```text
Input: s = "ab", p = ".*"
Output: true
```

Explanation:

`.` matches any single character and `*` allows it to repeat zero or more times.

Therefore:

```text
.*
```

can match any sequence of characters.

## Constraints

- `1 <= s.length <= 20`
- `1 <= p.length <= 20`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `.`, and `*`.
- Every `*` has a valid preceding character.

## Approach

Use dynamic programming to determine whether prefixes of the string and pattern match.

Define:

```text
dp[i][j]
```

as whether the first `i` characters of `s` match the first `j` characters of `p`.

### Normal Character or `.`

If the current pattern character is a regular character or `.`:

```text
p[j - 1] == s[i - 1]
```

or:

```text
p[j - 1] == '.'
```

then:

```text
dp[i][j] = dp[i - 1][j - 1]
```

### `*` Character

When the current pattern character is `*`, there are two possibilities.

#### Zero Occurrences

Ignore the preceding character and `*`:

```text
dp[i][j] = dp[i][j - 2]
```

#### One or More Occurrences

If the preceding pattern character matches the current input character:

```text
p[j - 2] == s[i - 1]
```

or:

```text
p[j - 2] == '.'
```

then the current input character can be consumed while keeping the same pattern:

```text
dp[i][j] = dp[i][j] || dp[i - 1][j]
```

## C Solution

```c
#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p)
{
    int sLength = strlen(s);
    int pLength = strlen(p);

    bool dp[sLength + 1][pLength + 1];

    for (int i = 0; i <= sLength; i++)
    {
        for (int j = 0; j <= pLength; j++)
        {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    for (int j = 2; j <= pLength; j++)
    {
        if (p[j - 1] == '*')
        {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= sLength; i++)
    {
        for (int j = 1; j <= pLength; j++)
        {
            if (p[j - 1] == s[i - 1] ||
                p[j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][