#include <stdlib.h>

static int compare_ints(const void *left, const void *right) {
    const int a = *(const int *)left;
    const int b = *(const int *)right;
    return (a > b) - (a < b);
}

int minimizeSum(int *nums, int numsSize) {
    qsort(nums, (size_t)numsSize, sizeof(nums[0]), compare_ints);

    int remove_two_largest = nums[numsSize - 3] - nums[0];
    int remove_one_each = nums[numsSize - 2] - nums[1];
    int remove_two_smallest = nums[numsSize - 1] - nums[2];

    int answer = remove_two_largest < remove_one_each
                     ? remove_two_largest : remove_one_each;
    return answer < remove_two_smallest ? answer : remove_two_smallest;
}
