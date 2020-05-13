class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int max = 0;
        vector<int> help_stack;
        prices.push_back(0);

        for(int i = 0; i < prices.size(); ++i)
        {
                while(!help_stack.empty() && (help_stack.back() > prices[i]))
                {
                    max = std::max(help_stack.back() - help_stack.front(), max);
                    help_stack.pop_back();
                }
            
            help_stack.push_back(prices[i]);
            
        }
    
        return max;
    }
};