//  https://leetcode.com/problems/camelcase-matching/description/


class Solution {
public:
    struct node{
        bool end;
        vector<node*> ch;
        node(){
            end = false;
            ch.resize(257,NULL);
        }
    };
    node* root = new node();
    
    void insert(string s){
        node* curr = root;
        for(auto c : s){
            if(curr->ch[c] == NULL){
                curr->ch[c] = new node();
            }
            curr = curr->ch[c];
        }
        curr->end = true;
    }
    
    bool search(string s, string p, node* root){
        node* curr = root;
        for(int i = 0; i < s.size(); i++){
		
            // if pattern end and their is capital letter
            if(p.size() == 0 && isupper(s[i])) return false;
			
            // if capital letter does not matches with pattern
            if(isupper(s[i]) && s[i] != p[0]) return false;
            
			// pattern matches
			if(s[i] == p[0]){
                p = p.substr(1);
            }
            if(curr->ch[s[i]] == NULL) return false;
            if(search(s.substr(1), p, curr->ch[s[i]])){
                return true;
            }
            return false;
        }
		
        // if string over but pattern still left
        if(p.size()) return false;
        return curr->end;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        for(auto s : queries){
			// inserting every string into trie
            insert(s);
        }
        vector<bool> ans;
        for(auto s : queries){
			// searching for pattern into string
            ans.push_back(search(s, pattern, root));
        }
        return ans;
    }
};