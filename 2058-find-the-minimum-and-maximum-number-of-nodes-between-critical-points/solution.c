//*****************************************************************************
//** 2058. Find the Minimum and Maximum Number of Nodes Between Critical     **
//** Points                                                         leetcode **
//*****************************************************************************
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize)
{
    int* retVal = malloc(2 * sizeof(int));

    *returnSize = 2;

    retVal[0] = -1;
    retVal[1] = -1;

    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return retVal;
    }

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    struct ListNode* next = curr->next;

    int index = 1;
    int firstCritical = -1;
    int previousCritical = -1;
    int minDistance = INT_MAX;

    while (next != NULL)
    {
        int isCritical = 0;

        if ((curr->val > prev->val && curr->val > next->val) ||
            (curr->val < prev->val && curr->val < next->val))
        {
            isCritical = 1;
        }

        if (isCritical)
        {
            if (firstCritical == -1)
            {
                firstCritical = index;
            }
            else
            {
                int distance = index - previousCritical;

                if (distance < minDistance)
                {
                    minDistance = distance;
                }

                retVal[1] = index - firstCritical;
            }

            previousCritical = index;
        }

        prev = curr;
        curr = next;
        next = next->next;
        index++;
    }

    if (minDistance != INT_MAX)
    {
        retVal[0] = minDistance;
    }

    return retVal;
}