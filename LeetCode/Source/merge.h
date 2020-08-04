class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() <= 1)
            // 可以换成 return {}
            return intervals;
        
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) -> bool
        {
            if(v1[0] < v2[0])
                return true;
            else if(v1[0] == v2[0] && v1[1] < v2[1])
                return true;
            else
                return false;
        });

        vector<int> pre = intervals[0];
        vector<vector<int>> ans;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(pre[1] >= intervals[i][0])
                pre[1] = std::max(intervals[i][1], pre[1]);
            else
            {
                ans.push_back(pre);
                pre = intervals[i];
            }
        }

        ans.push_back(pre);
        return ans;
    }
};