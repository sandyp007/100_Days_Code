// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        if(n ==1) {return true;}
        unordered_map <int,int> map;
        while (n >0) {
            int sum =0;
            while(n>0) {
                int x = n%10;
                sum+= x*x;
                n = n/10;
            }
            n = sum;
            map[n]++;
            if(map[n] > 1){return false;}
            if(n == 1) {return true;}
        }
        return false;
    }
};