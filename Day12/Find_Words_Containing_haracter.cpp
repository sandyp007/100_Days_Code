// https://leetcode.com/problems/find-words-containing-character/

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
         vector<int> f;
        for(int i=0;i<w.size();i++){
            if(w[i].find(x)!=string ::npos){
                f.push_back(i);
            }
        }
        return f;
    }
};