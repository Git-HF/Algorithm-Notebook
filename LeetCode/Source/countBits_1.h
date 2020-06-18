class Solution {
public:
    vector<int> countBits(int num) {

        
        vector<int> result(num+1, 0);

        int current_num = 1;
        int high_thes = 1;
        int low_thes = 0;
        while(current_num <= num)
        {
            if(current_num >= low_thes && current_num < high_thes)
            {
                result[current_num] = result[current_num - low_thes] + 1;
                ++current_num;

            }
            else
            {
                low_thes = high_thes;
                high_thes = high_thes << 1;
            }
        }

        return result;
    }
};