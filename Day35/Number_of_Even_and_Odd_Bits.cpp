//  https://leetcode.com/problems/number-of-even-and-odd-bits/

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int x = 0, o = 0, e = 0;
        while(n){
            x++;
            if(n&1)e++;
            n >>= 1;
            if(n==0)break;
            if(n&1)o++;
            n >>= 1;
            x++;
        }
            return {e,o};
    }
};