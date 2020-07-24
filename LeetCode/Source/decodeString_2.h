class Solution {
public:
    string decodeString(string s) {

        stack<string> help;

        int res = 0;
        string str = "";
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '[')
            {
                help.push(to_string(res));
                help.push(string(1, '['));
                res = 0;
            }
            else if(s[i] == ']')
            {
                while(help.top() != "[")
                {
                    str = help.top() + str;
                    help.pop();
                }
                help.pop();
                int times = stoi(help.top());
                help.pop();
                string cur_str = str;
                for(int i = 1; i < times; ++i)
                {
                    cur_str += str;
                }

                help.push(cur_str);
                str = "";
                res = 0;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                res = res * 10 + (s[i] - '0');
                if(str != "")
                {
                    help.push(str);
                    str = "";
                }
            }
            else
            {
                str += s[i];
            }
        }

        while(!help.empty())
        {
            str = help.top() + str;
            help.pop();
        }

        return str;
    }
};