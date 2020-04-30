#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
#include "Swap.h"

using std::vector;
// -------------------------------经典快排---------------------
//right指向尾后元素,函数返回用于划分数组的值的索引。
int classical_partition(vector<int> & arr, int left, int right)
{
    //将首元素作为划分的依据,即arr[left],(注意不是arr[0])
    //less指向小于等于区域的尾后元素
    int less = left + 1;
    for(int i = left + 1; i < right; ++i)
    {
        if(arr[i] <= arr[left])
        {
            swap_int(arr[i], arr[less++]);
        }
    }
    swap_int(arr[less-1], arr[left]);
    return less-1;
}

//right指向尾后元素
void quick_sort_process(vector<int> &arr, int left, int right)
{
    //如果排序序列为0或者为1,则直接返回
    if(left + 1 >= right)
        return ;

    int p = classical_partition(arr, left, right);
    quick_sort_process(arr, left, p);
    quick_sort_process(arr, p+1, right);
}

void quick_sort(vector<int> &arr)
{
    if(arr.size() < 2)
        return;
    quick_sort_process(arr, 0, arr.size());
}


// --------------------使用荷兰国旗加速的快排---------------------
vector<int> Netherlands_flag_Partition(vector<int>& arr, int left, int right)
{
    //left指向小于区域尾后元素，right指向大于区域首元素
    int less = left + 1, more = right;
    int current = left+1;
    while(current < more)
    {
        if(arr[current] < arr[left])
            swap_int(arr[current++], arr[less++]);
        else if(arr[current] == arr[left])
            ++current;
        else
        {
            swap_int(arr[current], arr[--more]);
        }
    }

    swap_int(arr[left], arr[--less]);
    return vector<int>({less, more});
}

void quick_sort_process_1(vector<int> &arr, int left, int right)
{
    if(left + 1 >= right)
        return;
    
    vector<int> p = Netherlands_flag_Partition(arr, left, right);
    quick_sort_process_1(arr, left, p[0]);
    quick_sort_process_1(arr, p[1], right);
}

void quick_sort_1(vector<int> &arr)
{
    if(arr.size() < 2)
        return;
    quick_sort_process_1(arr, 0, arr.size());    
}

#endif