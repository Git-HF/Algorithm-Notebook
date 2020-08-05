class Solution {
public:
    int min_nums = INT_MAX;

    int coinChange(vector<int>& coins, int amount) {
        
        std::sort(coins.begin(), coins.end());

        process(coins, coins.size() - 1, amount, 0);

        return (min_nums == INT_MAX) ? -1 : min_nums;
    }

    void process(vector<int>& coins, int index, int amount, int cur_nums)
    {
        if(amount == 0)
        {
            min_nums = std::min(min_nums, cur_nums);
            return;
        }   

        if(index == -1)
            return;
        
        // i+cur_nums <= min_nums相当于剪树。
        for(int i = amount / coins[index]; i >= 0 && ((i + cur_nums) <= min_nums); --i)
        {
            process(coins, index-1, amount - (coins[index] * i), cur_nums+i);
        }
    }
};