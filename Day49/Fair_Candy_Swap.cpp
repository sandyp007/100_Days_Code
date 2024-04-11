// https://leetcode.com/problems/fair-candy-swap/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        map <int,int> mp;
        vector <int> v(2);
        int sum1=0,sum2=0;
        for(int i:bobSizes){
            mp[i]++;
            sum2+=i;
        } 
        for(int i:aliceSizes) sum1+=i;
        for(int i:aliceSizes){
            if(mp.find((sum2-sum1+i+i)/2)!=mp.end()){
                v[0]=i;
                v[1]=(sum2-sum1+i+i)/2;
                return v;
            }
        }
        return v;
    }
};