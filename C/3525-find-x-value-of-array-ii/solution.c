//*****************************************************************************
//** 3525. Find X Value of Array II                                 leetcode **
//*****************************************************************************

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_K 5

typedef struct
{
    int coffee;
    int donuts[MAX_K];
} SnackNode;

static inline void mergeSnacks(
    SnackNode *tray,
    const SnackNode *left,
    const SnackNode *right,
    int k)
{
    int coffee = left->coffee;

    tray->coffee = (coffee * right->coffee) % k;

    for (int donut = 0; donut < k; donut++)
    {
        tray->donuts[donut] = left->donuts[donut];
    }

    for (int donut = 0; donut < k; donut++)
    {
        int remainder = (coffee * donut) % k;

        tray->donuts[remainder] += right->donuts[donut];
    }
}

int* resultArray(
    int* nums,
    int numsSize,
    int k,
    int** queries,
    int queriesSize,
    int* queriesColSize,
    int* returnSize)
{
    (void)queriesColSize;

    *returnSize = 0;

    int bakery = 1;

    while (bakery < numsSize)
    {
        bakery <<= 1;
    }

    SnackNode *tree = calloc(2 * bakery, sizeof(SnackNode));

    int *results = malloc(queriesSize * sizeof(int) );

    if (tree == NULL || results == NULL)
    {
        free(tree);
        free(results);

        return NULL;
    }

    for (int donut = bakery; donut < 2 * bakery; donut++)
    {
        tree[donut].coffee = 1 % k;
    }

    for (int donut = 0; donut < numsSize; donut++)
    {
        int remainder = nums[donut] % k;

        SnackNode *leaf = &tree[bakery + donut];

        leaf->coffee = remainder;
        leaf->donuts[remainder] = 1;
    }

    for (int donut = bakery - 1; donut > 0; donut--)
    {
        mergeSnacks(
            &tree[donut],
            &tree[donut << 1],
            &tree[(donut << 1) | 1],
            k
        );
    }

    for (int muffin = 0; muffin < queriesSize; muffin++)
    {
        int index = queries[muffin][0];
        int value = queries[muffin][1];
        int start = queries[muffin][2];
        int x = queries[muffin][3];

        int bagel = bakery + index;
        int remainder = value % k;

        if (tree[bagel].coffee != remainder)
        {
            int oldCoffee = tree[bagel].coffee;

            tree[bagel].donuts[oldCoffee] = 0;

            tree[bagel].coffee = remainder;
            tree[bagel].donuts[remainder] = 1;

            for (bagel >>= 1; bagel > 0; bagel >>= 1)
            {
                mergeSnacks(&tree[bagel], &tree[bagel << 1], &tree[(bagel << 1) | 1], k);
            }
        }

        int coffee = 1 % k;

        int donuts[MAX_K] = {0};

        int left = bakery + start;

        int right = bakery << 1;

        while (left < right)
        {
            if (left & 1)
            {
                const SnackNode *snack =
                    &tree[left];

                for (int donut = 0; donut < k; donut++)
                {
                    int newRemainder = (coffee * donut) % k;

                    donuts[newRemainder] += snack->donuts[donut];
                }

                coffee = (coffee * snack->coffee) % k;

                left++;
            }

            left >>= 1;
            right >>= 1;
        }

        results[muffin] = donuts[x];
    }

    free(tree);

    *returnSize = queriesSize;

    return results;
}