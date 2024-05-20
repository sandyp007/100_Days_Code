//  https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i]==words[j].substr(0,words[i].size()) && words[i]==words[j].substr(words[j].size()-words[i].size())) cnt++;
            }
        }
        return cnt;
    }
};