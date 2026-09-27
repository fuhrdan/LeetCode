//*****************************************************************************
//** 3. Longest Substring Without Repeating Characters              leetcode **
//*****************************************************************************

int lengthOfLongestSubstring(char* s)
{
    int lastSeen[256];

    for (int i = 0; i < 256; i++)
    {
        lastSeen[i] = -1;
    }

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++)
    {
        unsigned char ch = (unsigned char)s[right];

        if (lastSeen[ch] >= left)
        {
            left = lastSeen[ch] + 1;
        }

        lastSeen[ch] = right;

        int currentLength = right - left + 1;

        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }

    return maxLength;
}