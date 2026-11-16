#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* digitSum(char* s, int k)
{
    char* current = (char*)malloc(strlen(s) + 1);
    strcpy(current, s);

    while ((int)strlen(current) > k)
    {
        int length = (int)strlen(current);
        char* next = (char*)malloc(length + 1);
        int write = 0;

        for (int i = 0; i < length; i += k)
        {
            int sum = 0;

            for (int j = i; j < i + k && j < length; j++)
            {
                sum += current[j] - '0';
            }

            char buffer[16];
            int count = sprintf(buffer, "%d", sum);

            for (int j = 0; j < count; j++)
            {
                next[write++] = buffer[j];
            }
        }

        next[write] = '\0';
        free(current);
        current = next;
    }

    return current;
}
