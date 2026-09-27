public class Solution
{
    private void Reverse(char[] s, int left, int right)
    {
        while (left < right)
        {
            (s[left], s[right]) = (s[right], s[left]);
            left++;
            right--;
        }
    }

    public void ReverseWords(char[] s)
    {
        Reverse(s, 0, s.Length - 1);

        int start = 0;

        for (int i = 0; i <= s.Length; i++)
        {
            if (i == s.Length || s[i] == ' ')
            {
                Reverse(s, start, i - 1);
                start = i + 1;
            }
        }
    }
}
