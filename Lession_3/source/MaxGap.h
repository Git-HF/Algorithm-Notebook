#ifndef MAX_GAP_H
#define MAX_GAP_H

#include <vector>

using std::vector;

int get_bucket_num(int num, int len, int min, int max)
{
    return static_cast<int>((num - min) * len /(max - min));
}

int max_gap(const vector<int> &arr)
{
    if(arr.size() < 2)
        return 0;

    int min = arr[0], max = arr[0];

    for(int i = 1; i < arr.size(); ++i)
    {
        min = arr[i] < min ? arr[i] : min;
        max = arr[i] > max ? arr[i] : max;
    }

    if(min == max)
        return 0;
    
    vector<int> bucketMax(arr.size() + 1);
    vector<int> bucketMin(arr.size() + 1);
    vector<bool> bucketFlag(arr.size() + 1, false);
    
    for(int i = 0; i < arr.size(); ++i)
    {
        int num = get_bucket_num(arr[i], arr.size(), min, max);
        if(!bucketFlag[num])
        {
            bucketFlag[num] = true;
            bucketMax[num] = bucketMin[num] = arr[i];
        }
        else
        {
            bucketMin[num] = arr[i] < bucketMin[num] ? arr[i] : bucketMin[num];
            bucketMax[num] = arr[i] > bucketMax[num] ? arr[i] : bucketMax[num];
        }
    }

    int maxDef = 0;
    int preMax = bucketMax[0];
    for(int i = 1; i < arr.size() + 1; ++i)
    {
        if(bucketFlag[i])
        {
            maxDef = (bucketMin[i] - preMax) > maxDef ? (bucketMin[i] - preMax) : maxDef;
            preMax = bucketMax[i];
        }
    }

    return maxDef;
    
}
#endif