// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX; // least so far
        int op = 0;  // overall profit
        int pist = 0;  // profit if sold today
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf){
                lsf = prices[i];   // update our least so far
            }
            pist = prices[i] - lsf;   // calculating profit if sold today by, Buy - sell
            if(op < pist){    // if pist is more then our previous overall profit
                op = pist;  // update overall profit
            }
        }
        return op;
    }
};
