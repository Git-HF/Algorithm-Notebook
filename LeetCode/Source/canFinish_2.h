class Solution {
public:

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    //表示课程i是哪些课程的前置课程
	vector<vector<int>> course = vector<vector<int>>(numCourses, vector<int>());
    
    // 表示课程i的前置课程有几个
    vector<int> num_course = vector<int>(numCourses, 0);
	for (auto item : prerequisites)
	{
		course[item[1]].push_back(item[0]);
        ++num_course[item[0]];
	}

    queue<int> help;
    int sum = numCourses;
	for (int i = 0; i < numCourses; ++i)
	{
		if(num_course[i] == 0)
            help.push(i);
	}

    while(!help.empty())
    {
        int cur_index = help.front();
        help.pop();
        --sum;
        for(auto item: course[cur_index])
        {
            if(--num_course[item] == 0)
            {
                help.push(item);
            }
        }
    }

	return sum == 0;
}

};