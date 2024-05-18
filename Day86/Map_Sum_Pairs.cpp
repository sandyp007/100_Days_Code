//  https://leetcode.com/problems/map-sum-pairs/description/

class TrieNode {
public:
    int score = 0;
    TrieNode* child[26];
};
class MapSum {
public:
    int res = 0;
    /** Initialize your data structure here. */
    TrieNode* root;
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;
        for(char c : key) {
            if(!curr->child[c-'a']) {
                curr->child[c-'a'] = new TrieNode();
            }
            curr = curr->child[c-'a'];
        }
        curr->score = val;
    }
    
    int sum(string prefix) {
        res = 0;
        TrieNode* curr = root;
        for(char c : prefix) {
            if(!curr->child[c-'a']) 
                return 0;
            curr = curr->child[c-'a'];
        }
        helper(curr);
        return res;
    }
    void helper(TrieNode* curr) {
        res += curr->score;
        for (int i = 0; i < 26; i++) {
            if (curr->child[i]) {
                helper(curr->child[i]);
            }
        }
    }
};