int minInsertions(char* s)
{
    int insertions = 0;
    int needed = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            if (needed % 2 == 1)
            {
                insertions++;
                needed--;
            }

            needed += 2;
        }
        else
        {
            needed--;

            if (needed < 0)
            {
                insertions++;
                needed = 1;
            }
        }
    }

    return insertions + needed;
}
