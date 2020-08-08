class Solution {
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s) {

        if(s.size() < 4)
            return res;
        
        vector<string> tmp;
        process(s, tmp, 0, 4);
        return res;
    }

    bool valid(string str)
    {
        // 用来去重，不能丢
        if(str[0] == '0')
            return str.size() == 1;
        

        // stoll有很多种，stoi,stol等。
        return stoll(str) <= 255;
    }

    void process(string s, vector<string>& cur, int index, int count)
    {   
        // 必须放在前面
        // 不能丢
        if(index >= s.size())
            return;

        //if(count == 1 && index < s.size())如果if条件转换为这个，那么上面的条件可以不需要
        if(count == 1)
        {
            // 这一句不能少，否则字符串过长时，stoi会溢出。
            if(s.end() - s.begin() - index > 3)
                return;

            string tmp = string(s.begin()+index, s.end());
            if(!valid(tmp))
                return;
            
            cur.push_back(tmp);
            res.push_back(cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3]);
            cur.pop_back(); 
            return;
        }

        // i - index不能相当于减枝，不能丢
        for(int i = index; i < s.size() && i - index < 3; ++i)
        {
            string tmp_n = string(s.begin()+index, s.begin()+i+1);
            if(!valid(tmp_n))
                break;
            cur.push_back(tmp_n);
            process(s, cur, i+1, count-1);
            cur.pop_back();
        }
    }
};