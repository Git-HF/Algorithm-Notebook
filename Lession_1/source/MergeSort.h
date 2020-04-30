#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include "Swap.h"

using std::vector;
void sort_process(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);


void merge_sort(vector<int>& arr)
{
    if(arr.size() < 2)
        return;
    sort_process(arr, 0, arr.size());
}

//right指向尾后元素，而不是最后一个元素
void sort_process(vector<int>& arr, int left, int right)
{
    if(left + 1 == right)
        return;
    
    int mid = left + ((right - left) >> 1);
    sort_process(arr, left, mid);
    sort_process(arr, mid, right);
    merge(arr, left, mid, right);    
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> helpArr(right - left); 

    int startLeft = left, startRight = mid;
    int index = 0;
    while(startLeft < mid && startRight < right)
    {
        helpArr[index++] = arr[startLeft] < arr[startRight] ? arr[startLeft++] : arr[startRight++]; 
    }

    while(startLeft < mid)
    {
        helpArr[index++] = arr[startLeft++];
    }

    while (startRight < right)
    {
        helpArr[index++] = arr[startRight++];
    }

    //注意，这里不是从0开始的
    index = left;
    for(const int& item : helpArr)
    {
        arr[index++] = item;
    }
}
#endif 