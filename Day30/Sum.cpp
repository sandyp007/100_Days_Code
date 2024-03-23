//  https://leetcode.com/problems/sum-of-two-integers/
class Solution {
public:
    int getSum(int a, int b) 
    {
        return b? getSum(a^b, (a&b)<<1):a;
    }
};