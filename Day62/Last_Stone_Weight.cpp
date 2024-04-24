https://leetcode.com/problems/last-stone-weight/

//Solution 01:
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size(), ans, count = 0;
        
        if(n == 1) return stones[0];
        
        while(count != n-1){
            sort(stones.begin(), stones.end());
            stones[n-1] = stones[n-1] - stones[n-2];
            stones[n-2] = 0;
            count++;
        }
        return stones[n-1];
    }
};

Solution 02:
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> q;
        int x, y;
        
        for(auto x:stones)
            q.push(x);
        
        while(q.size() != 1){
            y = q.top();
            q.pop();
            x = q.top();
            q.pop();

            q.push(y-x);
        }
        
        return q.top();
    }
};