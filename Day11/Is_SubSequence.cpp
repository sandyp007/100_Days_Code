// https://leetcode.com/problems/is-subsequence/submissions/1192549012/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.size() && j < s.size(); ++i) {
            if (s[j] == t[i]) {
                ++j;
            }
            if (j == s.size()) {
                break;
            }
        }
        return j == s.size();
    }
};