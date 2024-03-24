// https://leetcode.com/problems/count-primes/ 

class Solution {
public:
    int countPrimes(int n) {
        bitset<5000000> bt;
        
        for(int i = 2; i<n; i++)
            bt.set(i);

        for(int i = 2; i<n; i++)
            if(bt[i])
                for(int j = 2; j*i < n; j++)
                    bt.reset(j*i);

        return bt.count();
    }
};