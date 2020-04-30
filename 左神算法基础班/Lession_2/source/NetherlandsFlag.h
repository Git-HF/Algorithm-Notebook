#ifndef NETHERLANDS_FLAG_H
#define NETHERLANDS_FLAG_H

#include <vector>
#include "Swap.h"

using std::vector;

vector<int> Netherlands_flag(vector<int>& arr, int num)
{
    //less表示小于区域的尾后元素，more表示大于区域的首元素
    int less = 0, more = arr.size();
    int current = 0;

    while(current < more)
    {
        if(arr[current] < num)
        {
            swap_int(arr[less++], arr[current++]);
        }
        else if(arr[current] == num)
        {
            ++current;
        }
        else
        {
            //注意，此处的current不需要加1
            swap_int(arr[current], arr[--more]);
        }
    }

    return vector<int>({less, more});
}
#endif