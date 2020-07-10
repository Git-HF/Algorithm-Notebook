class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        stack<int> help;

        vector<int> res = vector<int>(T.size());

        for(int i = 0; i < T.size(); ++i)
        {
            while(!help.empty() && T[help.top()] < T[i])
            {
                res[help.top()] = i - help.top();
                help.pop();
            }
            
            help.push(i);
        }

        return res;
    }
};