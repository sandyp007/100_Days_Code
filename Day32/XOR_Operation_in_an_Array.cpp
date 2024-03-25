// https://leetcode.com/problems/xor-operation-in-an-array/
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = ans ^ (start + (2 * i));
        }
        return ans;
    }
};