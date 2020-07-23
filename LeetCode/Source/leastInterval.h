class Solution {
public:

    static bool cmp(int a1, int a2)
    {
        return a1 > a2;
    }
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> count_vec(26);
        for(auto c : tasks)
        {
            ++count_vec[c - 'A'];
        }

        std::sort(count_vec.begin(), count_vec.end(), cmp);

        int time = 0;
        while(count_vec[0] > 0)
        {
            int cur_n = n;
            int i = 0;
            while(cur_n >= 0)
            {
                //防止数组越界
                if(i < 26)
                    //判断当前任务是否被执行完
                    if(count_vec[i] > 0)
                    {
                        --count_vec[i];
                        ++time;
                        --cur_n;
                        ++i;
                    }
                    else
                    {
                        //如果当前任务被执行完，则判断是否还需要继续下一轮
                        if(count_vec[0] == 0)
                        {
                            //如果不需要，所有任务都执行完
                            break;
                        }
                        else
                        {
                            //如果需要，则此轮剩下时间无法执行任务，只能轮空
                            time += (cur_n + 1);
                            break;
                        }
                    }
                // 在测试案例中，这个判断条件没有用。但是自我感觉当每个任务都需要执行，并且间隔时间大于26时，用到该判断条件
                else
                {
                    time += (cur_n + 1);
                    break;
                }
                
            }
            std::sort(count_vec.begin(), count_vec.end(), cmp);
        }

        return time;
    }
};