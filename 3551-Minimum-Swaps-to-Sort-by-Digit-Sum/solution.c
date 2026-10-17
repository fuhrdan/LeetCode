#include <stdlib.h>

typedef struct
{
    int value;
    int sum;
    int originalIndex;
} Item;

static int digitSum(int value)
{
    int retVal = 0;

    while (value > 0)
    {
        retVal += value % 10;
        value /= 10;
    }

    return retVal;
}

static int compareItems(const void* a, const void* b)
{
    const Item* left = (const Item*)a;
    const Item* right = (const Item*)b;

    if (left->sum != right->sum)
    {
        return left->sum - right->sum;
    }

    if (left->value < right->value)
    {
        return -1;
    }

    if (left->value > right->value)
    {
        return 1;
    }

    return 0;
}

int minSwaps(int* nums, int numsSize)
{
    Item* items = (Item*)malloc(sizeof(Item) * numsSize);
    int* target = (int*)malloc(sizeof(int) * numsSize);
    int* visited = (int*)calloc(numsSize, sizeof(int));

    if (items == NULL || target == NULL || visited == NULL)
    {
        free(items);
        free(target);
        free(visited);
        return 0;
    }

    for (int i = 0; i < numsSize; i++)
    {
        items[i].value = nums[i];
        items[i].sum = digitSum(nums[i]);
        items[i].originalIndex = i;
    }

    qsort(items, numsSize, sizeof(Item), compareItems);

    for (int i = 0; i < numsSize; i++)
    {
        target[items[i].originalIndex] = i;
    }

    int retVal = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (visited[i] || target[i] == i)
        {
            continue;
        }

        int current = i;
        int cycleLength = 0;

        while (!visited[current])
        {
            visited[current] = 1;
            current = target[current];
            cycleLength++;
        }

        retVal += cycleLength - 1;
    }

    free(items);
    free(target);
    free(visited);

    return retVal;
}
