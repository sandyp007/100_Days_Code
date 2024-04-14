// https://leetcode.com/problems/alternating-digit-sum/

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> v;
        int k=n;
        while(k){
            v.push_back(k%10);
            k=k/10;
        }
    int sze=v.size();  
    int l=1;
    int sum=0;  
    
    for(int i=sze-1; i>=0; i--){
        sum+=v[i]*l;
        l=l*(-1);
    }
    return sum;
    }
};