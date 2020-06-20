class Solution {
public:
    int numTrees(int n) {

        int sum = 0;
        for(int i = 1; i <= n; ++i)
            sum += process(i, 1, n);
        
        return sum;
    }

    int process(int root, int start, int end)
    {
        if(start == end)
            return 1;
        
        int left = 0; 
        for(int i = start; i < root; ++i)
                left += process(i, start, root - 1);


        int right = 0;
        for(int j = root+1; j <= end; ++j)
                right += process(j, root+1, end);

        if(left == 0)
            return right;
        else if(right == 0)
            return left;
        else
            return left * right;
    }
};