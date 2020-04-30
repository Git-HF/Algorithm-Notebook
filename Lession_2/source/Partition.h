#ifndef PARTITION_H
#define PARTITION_H

#include <vector>
#include "Swap.h"

using std::vector;

void simple_partition(vector<int>& arr, int num)
{
    //less表示尾后元素
    int less = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        if(arr[i] <= num)
        {
            swap_int(arr[less++], arr[i]);
        }
    }
}
#endif