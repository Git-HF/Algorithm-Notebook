class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();

        int ans = 0;
        for(int mid = 0; mid < (2*len - 1); ++mid)
        {
            int left = mid / 2;
            int right = mid / 2 + mid % 2;

            while(left >= 0 && right < len && s[left] == s[right])
            {
                ++ans;
                --left;
                ++right;
            }
        }

        return ans;
    }
};