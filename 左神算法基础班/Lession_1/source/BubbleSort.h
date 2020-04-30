#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "Swap.h"
#include <vector>

using std::vector;


void bubble_sort(vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    
    for(int end = arr.size()-1; end > 0; --end)
    {
        for(int j = 0; j < end; ++j)
        {
            if(arr[j] > arr[j+1])
                swap_int(arr[j], arr[j+1]);
        }
    }
}
#endif