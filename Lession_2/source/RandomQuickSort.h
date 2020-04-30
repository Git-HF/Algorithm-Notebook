#ifndef RANDOM_QUICK_SORT_H
#define RANDOM_QUICK_SORT_H

#include <vector>
#include "Swap.h"
#include <cstdlib>

using std::vector;
// --------------------使用荷兰国旗加速的随机快排---------------------
vector<int> random_Netherlands_flag_Partition(vector<int>& arr, int left, int right)
{
    //产生一个随机的索引，并且与首元素互换
    swap_int(arr[left], arr[(rand()%(right - left)) + left]);
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

void random_quick_sort_process(vector<int> &arr, int left, int right)
{
    if(left + 1 >= right)
        return;
    
    vector<int> p = random_Netherlands_flag_Partition(arr, left, right);
    random_quick_sort_process(arr, left, p[0]);
    random_quick_sort_process(arr, p[1], right);
}

void random_quick_sort(vector<int> &arr)
{
    if(arr.size() < 2)
        return;
    random_quick_sort_process(arr, 0, arr.size());    
}

#endif