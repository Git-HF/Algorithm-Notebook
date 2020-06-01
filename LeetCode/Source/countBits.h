class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> result;

        for(int i = 0; i <= num; ++i)
        {
            int cur_num = i;
            int count = 0;
            for(int j = 0; j < 32; ++j)
            {
                if(cur_num %  2 == 1)
                    ++count;
                cur_num = cur_num >> 1;
            }

            result.push_back(count);
        }

        return result;
    }
};