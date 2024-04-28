//  https://leetcode.com/problems/sorting-the-sentence/

class Solution {
public:
    string sortSentence(string s) {
        string ans;
        for(int i=1;i<=9;i++) {
            int start = 0;
            for(int j=0;j<s.size();j++) {
                if(s[j] - '0' == i) {
                    ans.append(s, start, j - start);
                    ans.push_back(' ');
                    break;
                }
                if(s[j] == ' ') start = j + 1; 
            }
        }
        ans.resize(ans.size() - 1);
        return ans;
    }
};