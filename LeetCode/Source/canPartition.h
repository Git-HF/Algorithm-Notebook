class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }
        if(sum % 2 == 1)
            return false;
        
        int target = sum / 2;
        cout << nums.size() << endl;
        dp = vector<vector<int>>(nums.size(), vector<int>(target+1, -1));
        for(int i = 0; i < nums.size(); ++i)
        {
            // 如果数组的列数为target时，需要判断是否有元素大于这个值，如果大于，直接认为false；
            //或者将dp数组的列数设为sum，但这样太浪费空间了
            if(nums[i] <= target)
                dp[i][nums[i]] = 1;
        }
        
        return process(nums, 0, target);
    }

    bool process(vector<int>& vec, int index, int target)
    {
        if(index >= vec.size())
            return false;

        if(target < 0)
            return false;
        else if(target == 0)
            return true;
        
        if(dp[index][target] == 1)
            return true;
        else if(dp[index][target] == 0)
            return false;
            
        
        for(int i = index; i < vec.size(); ++i)
        {
            if(process(vec, i+1, target - vec[i]))
            {
                dp[index][target] = 1;
                return true;
            }
        }
        dp[index][target] = 0;
        return false;
    }
};