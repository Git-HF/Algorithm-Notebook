class Solution {
public:
    // 注意sort函数中自定义比较函数的使用
    static bool comp(vector<int> v1, vector<int> v2)
    {
        if(v1[0] > v2[0])
            return true;
        else if(v1[0] < v2[0])
            return false;
        else if(v1[1] < v2[1])
            return true;
        else
            return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), comp);

        vector<vector<int>> res = vector<vector<int>>();
        for(int i = 0; i < people.size(); ++i)
        {
            res.insert(res.begin() + people[i][1], people[i]);
        }

        return res;
    }
};