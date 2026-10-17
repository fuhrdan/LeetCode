class Solution
{
private:
    int digitSum(int value)
    {
        int retVal = 0;

        while (value > 0)
        {
            retVal += value % 10;
            value /= 10;
        }

        return retVal;
    }

public:
    int minSwaps(vector<int>& nums)
    {
        struct Item
        {
            int value;
            int sum;
            int originalIndex;
        };

        vector<Item> items;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            items.push_back({nums[i], digitSum(nums[i]), i});
        }

        sort(items.begin(), items.end(),
            [](const Item& a, const Item& b)
            {
                if (a.sum != b.sum)
                {
                    return a.sum < b.sum;
                }

                return a.value < b.value;
            });

        vector<int> target(nums.size());

        for (int i = 0; i < (int)items.size(); i++)
        {
            target[items[i].originalIndex] = i;
        }

        vector<bool> visited(nums.size(), false);
        int retVal = 0;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (visited[i] || target[i] == i)
            {
                continue;
            }

            int current = i;
            int cycleLength = 0;

            while (!visited[current])
            {
                visited[current] = true;
                current = target[current];
                cycleLength++;
            }

            retVal += cycleLength - 1;
        }

        return retVal;
    }
};
