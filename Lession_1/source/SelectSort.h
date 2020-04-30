#ifndef SELECT_SORT_H
#define SELECT_SORT_H

#include <vector>
#include "Swap.h"

using std::vector;

void select_sort(vector<int> &arr)
{
    if(arr.size() < 2)
        return;

    int minIndex;
    for(int i = 0; i < arr.size() - 1; ++i)
    {
        minIndex = i;
        for(int j = i+1; j < arr.size(); ++j)
        {
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap_int(arr[minIndex], arr[i]);
    }
}
#endif