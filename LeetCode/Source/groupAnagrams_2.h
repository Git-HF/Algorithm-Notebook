
class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string, int> help;

        for(int i = 0; i < strs.size(); ++i)
        {
            string tmp_str = strs[i];
            sort(tmp_str.begin(), tmp_str.end());
            if(help.count(tmp_str) == 0)
            {
                res.push_back(vector<string>());
                help[tmp_str] = res.size() - 1;
                
            }
            res[help[tmp_str]].push_back(strs[i]);
        }

        return res;
    }
};