class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {


        return process(heights, 0, heights.size() - 1);
    }

    int MaxFunc(int i, int j)
    {
        return (i > j) ? i : j;
    }

    int process(const vector<int>& heights, int left, int right)
    {
        if(left > right)
            return 0;

        int min_index = left;
        for(int i = left + 1; i <= right; ++i)
        {
            if(heights[i] < heights[min_index])
                min_index = i;
        }

        int current_area = (right - left + 1) * heights[min_index];
        int left_area = process(heights, left, min_index - 1);
        int right_area = process(heights, min_index + 1, right);

        return MaxFunc(current_area, MaxFunc(left_area, right_area));       
    }
};