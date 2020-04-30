class Solution {
public:

    //方法1、 因为每行都是递增的， 按行进行二分查找
    //时间复杂度O(M * logN) M为行数，N为列数  空间复杂度O(1)
    int binary_search(vector<int>& v, int target)
    {
        int left = 0;
        int right = v.size() - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(v.at(mid) == target)
                return mid;
            else if(target > v.at(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i = 0; i < matrix.size(); ++i)
        {
            if(binary_search(matrix.at(i), target) != -1)
                return true;
        }
        return false;
    }