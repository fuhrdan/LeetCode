#include <string.h>

static void reverseRange(char* s, int left, int right)
{
    while (left < right)
    {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

void reverseWords(char* s, int sSize)
{
    reverseRange(s, 0, sSize - 1);

    int start = 0;

    for (int i = 0; i <= sSize; i++)
    {
        if (i == sSize || s[i] == ' ')
        {
            reverseRange(s, start, i - 1);
            start = i + 1;
        }
    }
}
