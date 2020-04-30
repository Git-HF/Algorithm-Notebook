#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include <vector>
#include "Swap.h"

using std::vector;

void insert_sort(vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return;
    }

    for(int i = 1; i < arr.size(); ++i)
    {
        //注意当使用交换操作和后移操作，操作不一样;

        /*
        int j = i-1;
        int currentValue = arr[i];
        while ((j>=0)&&(arr[j] > currentValue))
        {
            arr[j+1] = arr[j];
            //swap_int(arr[j], arr[j-1]);
            --j;
        }
        arr[j+1] = currentValue;
        */

        for(int j = i; j > 0 && arr[j-1] > arr[j]; --j)
        {
            swap_int(arr[j-1], arr[j]);
        }
    }
    

}

#endif