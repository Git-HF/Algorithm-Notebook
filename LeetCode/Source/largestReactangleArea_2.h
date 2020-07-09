class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        if(heights.size() == 0)
            return 0;

        stack<int> help_stack;

        int maxArea = -1;
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!help_stack.empty() && heights[help_stack.top()] > heights[i])
            {
                int index = help_stack.top();
                help_stack.pop();

                int left;
                if(help_stack.empty())
                    left = -1;
                else
                    left = help_stack.top();

                int current_area = (i - left - 1) * heights[index];
                maxArea = (current_area > maxArea) ? current_area : maxArea;
            }

            help_stack.push(i);
        }        

        // 在辅助栈中，最后一个元素必定是数组的长度。
        int end = heights.size();
        while(!help_stack.empty())
        {
            int index = help_stack.top();
            help_stack.pop();

            int left;
            if(help_stack.empty())
                left = -1;
            else
                left = help_stack.top();

            int current_area = (end - left - 1) * heights[index];
            maxArea = (current_area > maxArea) ? current_area : maxArea;
        }

        return maxArea;
    }
};