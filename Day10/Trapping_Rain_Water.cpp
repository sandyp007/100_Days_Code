// https://leetcode.com/problems/trapping-rain-water/submissions/1191510160/

class Solution {
public:
  
   int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
};