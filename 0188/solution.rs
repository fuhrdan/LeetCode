impl Solution
{
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32
    {
        let k = k as usize;
        let n = prices.len();

        if k >= n / 2
        {
            return prices.windows(2)
                .map(|w| (w[1] - w[0]).max(0))
                .sum();
        }

        let mut buy = vec![i32::MIN / 2; k + 1];
        let mut sell = vec![0; k + 1];

        for price in prices
        {
            for t in 1..=k
            {
                buy[t] = buy[t].max(sell[t - 1] - price);
                sell[t] = sell[t].max(buy[t] + price);
            }
        }

        sell[k]
    }
}
