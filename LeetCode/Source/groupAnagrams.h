class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string, vector<string>> help;

        for(int i = 0; i < strs.size(); ++i)
        {
            string tmp_str = strs[i];
            sort(tmp_str.begin(), tmp_str.end());
            if(help.count(tmp_str) == 0)
            {
                help[tmp_str] = vector<string>();
                
            }
            help[tmp_str].push_back(strs[i]);
        }

        for(auto item = help.begin(); item != help.end(); ++item)
        {
            res.push_back(item->second);
        }

        return res;
    }
};