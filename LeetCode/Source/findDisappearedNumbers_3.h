class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            if(nums[nums[i]-1] != nums[i]){
                int tmp = nums[i];
                nums[i] = nums[tmp-1];
                nums[tmp-1] = tmp;
            } else {
                i++;
            }
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                res.push_back(i+1);
            }
        }
        return res;
    }
};