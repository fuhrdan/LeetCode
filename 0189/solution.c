static void reverseRange(int* nums, int left, int right)
{
    while (left < right)
    {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    if (numsSize <= 1)
    {
        return;
    }

    k %= numsSize;

    reverseRange(nums, 0, numsSize - 1);
    reverseRange(nums, 0, k - 1);
    reverseRange(nums, k, numsSize - 1);
}
