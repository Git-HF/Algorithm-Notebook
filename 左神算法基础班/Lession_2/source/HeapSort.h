#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>
#include "Swap.h"

using std::vector;

//index表示要插入的值的索引，heapsize表示当前堆的大小
//堆中元素需要向上调整的函数
//默认建立大跟堆
void heap_insert(vector<int> &arr, int index)
{
    int parent = ((index - 1) / 2);
    while(arr[index] > arr[parent])
    {
        swap_int(arr[index], arr[parent]);
        index = parent;
        //注意此处更新parent;
        parent = ((index - 1) / 2);
    }
}

//堆中元素需要向下调整的函数
void heap_ify(vector<int>& arr, int index, int heapSize)
{
    int leftChildren = 2 * index + 1;
    int maxChildren;
    while(leftChildren < heapSize)
    {
        maxChildren = (leftChildren+1 < heapSize)&&(arr[leftChildren] < arr[leftChildren+1]) ? leftChildren+1 : leftChildren;

        if(arr[index] >= arr[maxChildren])
            break;
        else
        {
            swap_int(arr[index], arr[maxChildren]);
            index = maxChildren;
            //注意此处更新leftChildren
            leftChildren = 2*index + 1;
        }
    }
}

void heap_sort(vector<int> &arr)
{
    if(arr.size() < 2)
        return;
    
    for(int i = 1; i < arr.size(); ++i)
        heap_insert(arr, i);
    
    int heapSize = arr.size();
    for(int i = arr.size() - 1; i > 0; --i)
    {
        swap_int(arr[0], arr[i]);
        heap_ify(arr, 0, --heapSize);
    }

}
#endif