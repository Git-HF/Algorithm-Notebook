class Solution {
public:
    bool process(vector<vector<int>>& course, int index, set<int> help)
{

	while (course[index].size() != 0)
	{
		if (help.count(index) == 1)
			return false;
		help.insert(index);

		/*
		for (int i = 0; i < course[index].size(); ++i)
		{
			if (!process(course, course[index][i], help))
			{
				return false;
			}
			course[index].erase(course[index].begin() + i);
		}
		*/

        //注意这里必须使用迭代器，因为需要一边遍历，一边删除数组中元素
		auto i = course[index].begin();
		while(i != course[index].end())
		{
			if (!process(course, *i, help))
			{
				return false;
			}
			i = course[index].erase(i);
		}

		
	}

	//course[index].clear();
	return true;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

	vector<vector<int>> course = vector<vector<int>>(numCourses, vector<int>());

	for (auto item : prerequisites)
	{
		course[item[0]].push_back(item[1]);
	}

	for (int i = 0; i < numCourses; ++i)
	{
		if (course[i].size() == 0)
			continue;
		else
		{
			set<int> help;
			if (!process(course, i, help))
				return false;
		}
	}

	return true;
}

};