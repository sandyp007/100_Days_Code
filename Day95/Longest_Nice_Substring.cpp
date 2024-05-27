//  https://leetcode.com/problems/longest-nice-substring/

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if(n<2){
            return "";
        }

        pair<int,int> ans= {-1,-1};

        for(int i=0;i<n;++i){
            int lower = 0,upper =0;
            for(int j=i;j<n;++j){
                if(s[j]>'Z'){
                    lower |= (1<<(s[j]-'a'));
                }else{
                    upper |= (1<<(s[j]-'A'));
                }
                if(upper == lower && j-i+1 > ans.second - ans.first+1){
                    ans = {i,j};
                }
            }
        }
        if (ans.first == -1){
            return "";
        }
        return s.substr(ans.first,ans.second-ans.first+1);
    }
};