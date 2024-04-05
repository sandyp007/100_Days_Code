//  https://leetcode.com/problems/time-needed-to-buy-tickets/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& ts, int k) {
        // support variables
        int res = 0;
        // running loops until we get all our tickets
        while (ts[k]) {
            // running one loop
            for (int i = 0, lmt = ts.size(); i < lmt && ts[k]; i++) {
                // decreasing one slot and increasing res, if the slot still queues
                if (ts[i]) {
                    ts[i]--;
                    res++;
                }
            } 
        }
        return res;
    }
};