# 1. Two Sum

**Difficulty:** Easy  
**LeetCode:** [Two Sum](https://leetcode.com/problems/two-sum/)

## Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

You may assume that each input has exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## Examples

### Example 1

```text
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
```

Explanation:

```text
nums[0] + nums[1] = 2 + 7 = 9
```

So the answer is:

```text
[0,1]
```

### Example 2

```text
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

### Example 3

```text
Input: nums = [3,3], target = 6
Output: [0,1]
```

## Constraints

- `2 <= nums.length <= 10000`
- `-1000000000 <= nums[i] <= 1000000000`
- `-1000000000 <= target <= 1000000000`
- Exactly one valid answer exists.

## Approach

Use a hash table to store numbers that have already been seen along with their indices.

For each element:

1. Calculate the required complement:

```text
complement = target - nums[i]
```

2. Check whether the complement already exists in the hash table.
3. If it does, return the stored index and the current index.
4. Otherwise, insert the current value and index into the table.

Because each element is processed once, this avoids checking every possible pair.

## C Solution

```c
#include <stdlib.h>

typedef struct
{
    int key;
    int index;
    int used;
} HashEntry;

static unsigned int hashValue(int value, int size)
{
    unsigned int hash = (unsigned int)value;

    hash ^= hash >> 16;
    hash *= 0x7feb352d;
    hash ^= hash >> 15;

    return hash % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int tableSize = numsSize * 2 + 1;

    HashEntry* table = calloc(tableSize, sizeof(HashEntry));

    if (table == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];

        unsigned int pos = hashValue(complement, tableSize);

        while (table[pos].used)
        {
            if (table[pos].key == complement)
            {
                int* retVal = malloc(2 * sizeof(int));

                if (retVal == NULL)
                {
                    free(table);
                    *returnSize = 0;
                    return NULL;
                }

                retVal[0] = table[pos].index;
                retVal[1] = i;

                *returnSize = 2;

                free(table);

                return retVal;
            }

            pos = (pos + 1) % tableSize;
        }

        pos = hashValue(nums[i], tableSize);

        while (table[pos].used)
        {
            pos = (pos + 1) % tableSize;
        }

        table[pos].key = nums[i];
        table[pos].index = i;
        table[pos].used = 1;
    }

    free(table);

    *returnSize = 0;
    return NULL;
}
```

## Complexity

- **Time:** `O(n)` average
- **Space:** `O(n)`

The hash table allows each complement lookup to be performed in average constant time.