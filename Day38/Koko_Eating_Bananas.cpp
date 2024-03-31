//  https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1;
        for(int pile : piles){
            right = max(right, pile);
        }
        
        while(left<right) {
            int mid = left + (right-left)/2;
            int hours = 0;
            for(int pile: piles){
                hours += ceil(pile*1.0/mid);
            }
            if(hours<=h){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
};