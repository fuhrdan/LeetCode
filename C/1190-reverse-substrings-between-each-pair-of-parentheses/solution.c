//*****************************************************************************
//** 1190. Reverse Substrings Between Each Pair of Parentheses      leetcode **
//*****************************************************************************

char* reverseParentheses(char* s)
{
    int len = strlen(s);

    char* retVal = malloc((len + 1) * sizeof(char));
    int* stack = malloc(len * sizeof(int));

    int retLen = 0;
    int stackTop = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            stack[stackTop] = retLen;
            stackTop++;
        }
        else if (s[i] == ')')
        {
            stackTop--;

            int left = stack[stackTop];
            int right = retLen - 1;

            while (left < right)
            {
                char temp = retVal[left];
                retVal[left] = retVal[right];
                retVal[right] = temp;

                left++;
                right--;
            }
        }
        else
        {
            retVal[retLen] = s[i];
            retLen++;
        }
    }

    retVal[retLen] = '\0';

    free(stack);

    return retVal;
}