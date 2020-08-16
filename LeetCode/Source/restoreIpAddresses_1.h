class Solution {
public:

    vector<string> res;

    bool validate(string str)
    {
        if(str.size() >= 4)
            return false;

        if(str[0] == '0' && str.size() != 1)
            return false;
        
        return stoi(str) <= 255;
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> cur;
        process(s, 0, 4, cur);
        return res;
    }

    void process(string str, int index, int count, vector<string> cur)
    {
        if(index >= str.size())
            return;
    
        if(count != 1)
        {
            for(int i = index; i < str.size(); ++i)
            {
                string tmp = string(str.begin()+index,str.begin()+i+1);
                if(!validate(tmp))
                {
                    break;
                }
                cur.push_back(tmp);
                process(str, i+1, count-1, cur);
                cur.pop_back();
            }
        }
        else
        {
            string tmp = string(str.begin()+index, str.end());
            if(!validate(tmp))
               return;
                
            cur.push_back(tmp);
            res.push_back(cur[0]+"."+cur[1]+"."+cur[2]+"."+cur[3]);
            cur.pop_back();
        }
    }
};