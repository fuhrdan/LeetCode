using System;

public class Solution
{
    public int MaxProfit(int k, int[] prices)
    {
        int n = prices.Length;

        if (k >= n / 2)
        {
            int retVal = 0;

            for (int i = 1; i < n; i++)
            {
                retVal += Math.Max(0, prices[i] - prices[i - 1]);
            }

            return retVal;
        }

        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];

        Array.Fill(buy, int.MinValue / 2);

        foreach (int price in prices)
        {
            for (int t = 1; t <= k; t++)
            {
                buy[t] = Math.Max(buy[t], sell[t - 1] - price);
                sell[t] = Math.Max(sell[t], buy[t] + price);
            }
        }

        return sell[k];
    }
}
