class Solution {
public:
    int mySqrt(int x) {
        
        int left = 0, right = x;
        long long pos = -1;
        while(left <= right)
        {
            long long mid = (left + right)/2;
            long long cur = mid * mid;
            
            if(cur == x)
                return mid;
            else if(cur < x)
            {
                left = mid+1;
                pos = mid;
            }
            else
                right = mid-1;
        }
        return pos;
    }
};