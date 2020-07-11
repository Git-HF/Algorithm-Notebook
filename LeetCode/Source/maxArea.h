class Solution {
public:

    int max_water = 0;
    int maxArea(vector<int>& height) {

        int left = 0, right = height.size() - 1;

        while(left < right)
        {
            int cur_water = std::min(height[left], height[right]) * (right - left);
            max_water = std::max(max_water, cur_water);
            if(height[left] < height[right])
                ++left;
            else
                --right;
        }

        return max_water;
    }
};