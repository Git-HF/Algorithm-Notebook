class Solution {
public:
    // 用set来存储，可以实现快速查找
    set<int> thres;
    bool is_divided(int n, int count)
    {
        if(count == 1)
            return thres.count(n) == 1;
        
        for(int i = 1; i * i <=n; ++i)
        {
            if(is_divided(n - i * i, count - 1))
                return true;
        }
        return false;
    }

    int numSquares(int n) {

        for(int i = 0; i * i <= n; ++i)
        {
            thres.insert(i*i);
        }

        int i;
        for(i = 1; i <= n; ++i)
        {
            if(is_divided(n, i))
                break;
        }

        return i;
    }
};