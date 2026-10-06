int minAddToMakeValid(char* s)
{
    int balance = 0;
    int needed = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            balance++;
        }
        else
        {
            if (balance > 0)
            {
                balance--;
            }
            else
            {
                needed++;
            }
        }
    }

    return needed + balance;
}
