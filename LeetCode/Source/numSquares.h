class Solution {
public:
    unordered_map<int, int> help;
    int numSquares(int n) {
        if(n < 0)
            return -1;
        if(n == 0)
            return 0;
        if(n == 1)
        {
            return 1;
        }
        
        if(help.count(n) == 1)
            return help[n];

        int max_count = int(sqrt(n));
        int min = n;
        for(int i = max_count; i >= 1; --i)
        {

            int tmp;
            if(n % (i*i) == 0)
            {
                tmp = n / (i*i);
                min = min < tmp ? min : tmp;
                continue;
            }
            else
                tmp = numSquares(n - i * i);
            
            if(tmp < 0)
                continue;
            else
            {
                //help[n] = (tmp + 1);
                min = min < (tmp + 1) ? min : tmp + 1;
            }
        }

        help[n] = min;
        return help[n];
    }
};