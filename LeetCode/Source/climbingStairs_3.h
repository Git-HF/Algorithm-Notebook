class Solution {
public:
    long long GetCni(int n, int i) {
        i = (n - i > i)? i : (n - i);
        if(i == 0) return 1;
        else return GetCni(n, i-1)*(n-i+1)/i;
    }
    int climbStairs(int n) {
        int i = 0;
        int Sum = 0;
        while(i <= n/2) {
            Sum += GetCni(n-i, i);
            //cout << "i = " << i << "Cni = " << Sum << "\n";
            i++;
        }

        return Sum;
    }
};