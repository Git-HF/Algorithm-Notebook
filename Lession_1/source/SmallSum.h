#ifndef SMALL_SUM_H
#define SMALL_SUM_H

#include <vector>

using std::vector;

int merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> helpArr(right - left);
    int startLeft = left, startRight = right;
    int index = 0;
    int sum = 0;
    while (startLeft < mid && startRight < right)
    {
        sum += arr[startLeft] < arr[startRight] ? arr[startLeft] * (right - startRight) : 0; 
        helpArr[index++] = arr[startLeft] < arr[startRight] ? arr[startLeft++] : arr[startRight++]; 
    }

    while(startLeft < mid)
    {
        helpArr[index++] = arr[startLeft++];
    }

    while(startRight < right)
    {
        helpArr[index++] = arr[startRight++];
    }

    index = left;
    for(const int& item : helpArr)
    {
        arr[index++] = item;
    }

    return sum;
}

int process_small_sum(vector<int>& arr, int left, int right)
{
    if(left + 1 == right)
        return 0;

    return process_small_sum(arr, left, mid) + process_small_sum(arr, mid, right) + merge(arr, left, mid, right);
}

int small_sum(vector<int> arr)
{
    if(arr.size() < 2)
        return 0;
    
    process_small_sum(arr, 0, arr.size());
}

#endif