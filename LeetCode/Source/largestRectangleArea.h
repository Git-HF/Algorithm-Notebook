class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        if(heights.size() == 0)
            return 0;
            
        int max_area = -1;
        for(int i = 0; i < heights.size(); ++i)
        {
            int area = GetArea(i, heights);
            max_area = (max_area > area) ? max_area : area;
        }

        return max_area;
    }

    int GetArea(int index, const vector<int>& heights)
    {
        int left = index;
        while(left > 0 && heights[index] <= heights[left])
        {
            --left;
        }

        if(heights[index] > heights[left])
            ++left;
        
        int right = index;
        while(right < heights.size() - 1 && heights[index] <= heights[right])
        {
            ++right;
        }
        if(heights[index] > heights[right])
            --right;
        
        return (right - left + 1) * heights[index];
    }
};