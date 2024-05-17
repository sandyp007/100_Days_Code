//  https://leetcode.com/problems/longest-common-prefix/description/  

class Tries {
    public:
    char data;
    Tries* arr[26];
    bool isTerminal;
    int child;
    Tries(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }
        isTerminal = false;
        child = 0;
    }
};
class TrieNode {
public:


    Tries* root = new Tries('#');



    void insertion(string s) {
        Tries* tmp = root;
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (tmp->arr[index] == nullptr) {
                (tmp->child)++;
                tmp->arr[index] = new Tries(s[i]);
            }
            tmp=tmp->arr[index];
        }
        tmp->isTerminal = true;
    }

    string prefix(string s) {
        Tries* tmp = root;
        string pre = "";
        for (int i = 0; i < s.length(); i++) {
            if(tmp->isTerminal){
               
                return pre;
            }
            if (tmp->child == 1) {
                pre.push_back(s[i]);
               
            } else {
                return pre;
            }
            tmp = tmp->arr[int(s[i] - 'a')];
        }
        return pre;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        TrieNode* trie=new TrieNode();
        for (int i = 0; i < strs.size(); i++) {
            trie->insertion(strs[i]);
        }
        string pre = trie->prefix(strs[0]);
        return pre;
    }
};