class Solution {
public:
    vector<string> letterCombinations(string digits) {

        map<int, string> help;
        help[2] = "abc";
        help[3] = "def";
        help[4] = "ghi";
        help[5] = "jkl";
        help[6] = "mno";
        help[7] = "pqrs";
        help[8] = "tuv";
        help[9] = "wxyz";

        if(digits.size() == 0)
            return vector<string>();
        
        vector<string> res;
        for(auto item : help[digits[0] - '0'])
        {
            res.push_back(string(1, item));
            //res.emplace_back(item);
        }

        for(int i = 1; i < digits.size(); ++i)
        {
            res = union_two(res, help[digits[i] - '0']);
        }

        return res;
    }

    vector<string> union_two(vector<string> &res, string newStr)
    {
        vector<string> ans;
        for(auto item: res)
        {
            for(auto c : newStr)
            {
                ans.push_back(item + c);
            }
        }

        return ans;
    }
};