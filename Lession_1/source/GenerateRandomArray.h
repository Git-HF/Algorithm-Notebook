#ifndef GENERATE_RANDOM_ARRAY_H
#define GENERATE_RANDOM_ARRYA_H

#include <cstdlib>
#include <vector>

using std::vector;

// 产生长度随机，并值在[-value, value]之间的vector。
vector<int> generate_random_array(int length, int value)
{
    int realLen = rand() % length;
    vector<int> arr(realLen);
    for(int& item : arr)
    {
        item = (rand()%(value+1)) - (rand()%(value+1));
    }
    return arr;
}

#endif