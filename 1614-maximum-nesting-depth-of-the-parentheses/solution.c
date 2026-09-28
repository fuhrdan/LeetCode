int maxDepth(char* s)
{
    int depth = 0;
    int retVal = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            depth++;

            if (depth > retVal)
            {
                retVal = depth;
            }
        }
        else if (s[i] == ')')
        {
            depth--;
        }
    }

    return retVal;
}
