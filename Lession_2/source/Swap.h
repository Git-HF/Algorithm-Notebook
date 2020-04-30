#ifndef SWAP_H
#define SWAP_H

void swap_int(int& a, int &b)
{
    if(a == b)
        return ;
    int tmp = a;
    a = b;
    b = tmp;
}
#endif