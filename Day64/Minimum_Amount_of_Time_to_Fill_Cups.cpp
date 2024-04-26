//  https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/


class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i=0; i<3; i++){
            pq.push(amount[i]);
        }
        int time=0;
        while(pq.top() != 0){
            time += 1;
            int temp = pq.top()-1;
            pq.pop();
            int temp2 = pq.top()-1;
            pq.pop();
            pq.push(temp);
            pq.push(temp2);
        }
        return time;
    }
};