class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int res=0;
    for(int i=0;i<32;i++)
    {
        int ones=0;
        for(int n:nums)
            ones += (n >> i) & 1;                        //位运算法统计每个位置上1出现的次数，每次出现则ones+1
        res += (ones > nums.size()/2) << i;              //如果1出现次数大于2分之1数组长，1即为这个位置的目标数字
    }
    return res;
}
};
