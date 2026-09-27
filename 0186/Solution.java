class Solution
{
    private void reverse(char[] s, int left, int right)
    {
        while (left < right)
        {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }

    public void reverseWords(char[] s)
    {
        reverse(s, 0, s.length - 1);

        int start = 0;

        for (int i = 0; i <= s.length; i++)
        {
            if (i == s.length || s[i] == ' ')
            {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
    }
}
