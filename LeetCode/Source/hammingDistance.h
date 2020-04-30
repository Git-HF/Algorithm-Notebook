class Solution {
public:
    int hammingDistance(int x, int y) {

        int tmp = x ^ y;

        int count = 0;
        while(tmp)
        {
            if(tmp & 1)
            {
                ++count;
            }
            tmp >>= 1;
        }

        /*
        // 别人的代码
        while ( n > 0)
        {
            counter += n & 1;
            n >>= 1;
        }
        */

        return count;
    }
};