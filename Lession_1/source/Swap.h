#ifndef SWAP_H
#define SWAP_H

void swap_int(int& a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
#endif