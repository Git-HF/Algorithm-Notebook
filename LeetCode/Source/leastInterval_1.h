class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<int> pri_que;
        vector<int> count_vec(26);
        for(auto item : tasks)
        {
            ++count_vec[item - 'A'];

        }

        for(auto item: count_vec)
        {
            if(item > 0)
                pri_que.push(item);
        }
        
        
        int times = 0;
        while(!pri_que.empty())
        {
            int cur_n = n;
            // queue<int>不支持clear操作
            queue<int> que;
            while(cur_n >= 0)
            {
                if(!pri_que.empty())
                {
                    if(pri_que.top() - 1 > 0)
                        que.push(pri_que.top() - 1);
                    pri_que.pop();
                    --cur_n;
                    ++times;
                }
                else
                {
                    if(!que.empty())
                    {
                        times += (cur_n + 1);
                    }
                    break;
                }
            }

            while(!que.empty())
            {
                pri_que.push(que.front());
                que.pop();
            }
        }

        return times;
        
    }
};