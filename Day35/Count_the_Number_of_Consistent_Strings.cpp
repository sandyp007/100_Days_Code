//  https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res=0;
        for(int i=0;i<allowed.size();i++){
            res |= 1 << (allowed[i]-'a');
        }
        int c=0;
        for(int i=0;i<words.size();i++){
            int c1=0;
            for(int j=0;j<words[i].size();j++){
                if(res & (1<<(words[i][j]-'a'))){
                    c1++;
                }
                if(c1==words[i].size())
                    c++;          
            }
        }
        return c;
        
    }
};