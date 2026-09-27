#include <stdlib.h>
#include <limits.h>

int maxProfit(int k, int* prices, int pricesSize)
{
    if (pricesSize < 2 || k == 0)
    {
        return 0;
    }

    if (k >= pricesSize / 2)
    {
        int retVal = 0;

        for (int i = 1; i < pricesSize; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                retVal += prices[i] - prices[i - 1];
            }
        }

        return retVal;
    }

    int* buy = malloc((k + 1) * sizeof(int));
    int* sell = calloc(k + 1, sizeof(int));

    for (int i = 1; i <= k; i++)
    {
        buy[i] = INT_MIN / 2;
    }

    for (int priceIndex = 0; priceIndex < pricesSize; priceIndex++)
    {
        int price = prices[priceIndex];

        for (int t = 1; t <= k; t++)
        {
            if (sell[t - 1] - price > buy[t])
            {
                buy[t] = sell[t - 1] - price;
            }

            if (buy[t] + price > sell[t])
            {
                sell[t] = buy[t] + price;
            }
        }
    }

    int retVal = sell[k];

    free(buy);
    free(sell);

    return retVal;
}
