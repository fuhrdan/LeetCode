//*****************************************************************************
//** 3876. Construct Uniform Parity Array II                        leetcode **
//*****************************************************************************

bool uniformArray(int* nums1, int nums1Size) {
    int mini = INT_MAX;

    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 == 1) {
            if (nums1[i] < mini) {
                mini = nums1[i];
            }
        }
    }

    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 == 0 && mini != INT_MAX && nums1[i] < mini) {
            return false;
        }
    }

    return true;
}