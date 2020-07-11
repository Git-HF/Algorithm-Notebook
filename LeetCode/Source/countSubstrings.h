class Solution {
public:
    vector<int> dp;

    int countSubstrings(string s) {
        int sum = 0;

        for(int i = 0; i < s.size(); ++i)
        {
            for(int j = i; j >= 0; --j)
            {
                sum += is_recuring(s, j, i);
            }
        }

        return sum;
    }

    bool is_recuring(const string& s, int left, int right)
    {
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            ++left;
            --right;
        }

        return true;
    }
};