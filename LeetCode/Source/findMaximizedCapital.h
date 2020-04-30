class Solution {
public:

    
    struct Projection_Captital
    {
        int capital_, profit_;

        bool operator<(const Projection_Captital& p) const
        {
            return this->capital_ > p.capital_;
        }
    };

    struct Projection_Profit
    {
        int capital_, profit_;

        bool operator<(const Projection_Profit& p) const
        {
            return this->profit_ < p.profit_;
        }
    };

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {

    priority_queue<Projection_Captital> small_heap;
    priority_queue<Projection_Profit> big_heap;

    Projection_Captital tmp;
    Projection_Profit tmp_profit;
    for(int i = 0; i < Profits.size(); ++i)
    {
        if(Capital[i] > W)
        {
            tmp.profit_ = Profits[i];
            tmp.capital_ = Capital[i];
            small_heap.push(tmp);
        }
        else
        {
            tmp_profit.profit_ = Profits[i];
            tmp_profit.capital_ = Capital[i];
            big_heap.push(tmp_profit);
        }
    }

    for(int i = 0; i < k; ++i)
    {
        if(!small_heap.empty())
        {
            while(!small_heap.empty() && small_heap.top().capital_ <= W)
            {
                tmp_profit.capital_ = small_heap.top().capital_;
                tmp_profit.profit_ = small_heap.top().profit_;

                small_heap.pop();

                big_heap.push(tmp_profit);
            }
        }

        if(big_heap.empty())
        {
            break;
        }
        else
        {
            W += big_heap.top().profit_;
            big_heap.pop();
        }
    }

    return W;
    }
};