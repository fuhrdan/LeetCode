//*****************************************************************************
//** 1. Two Sum                                                     leetcode **
//*****************************************************************************

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