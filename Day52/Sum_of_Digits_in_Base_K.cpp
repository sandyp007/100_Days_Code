//  https://leetcode.com/problems/sum-of-digits-in-base-k/

class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        vector<int>r;
        
        while(n!=0){
            int digit = n % k;
            r.push_back(digit);
            n = n/k;
        }
       
        for(int i=0; i<r.size(); i++){
            sum += r[i];
        }
        return sum;
    }
};