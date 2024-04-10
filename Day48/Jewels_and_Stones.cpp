// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
          int ans=0; 
    map<char,int>count;

    //counting all stones
    for(int i=0;i<stones.size();i++)
        count[stones[i]]++;          

    //sum all valid jewels stone
    for(int i=0;i<jewels.size();i++)
        ans+=count[jewels[i]];           

    return ans;
    }
};