//  https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int i=0;
        while(i<S.size()){
            int lastocc=S.find_last_of(S[i]);
            unordered_map<char,int> hg;
            for(int j=i+1;j<lastocc;j++){
                hg[S[j]]=S.find_last_of(S[j]);
                lastocc=max(lastocc,hg[S[j]]);
            }
            ans.push_back(lastocc-i+1);
            i=lastocc+1;
        }
        return ans;
    }
};