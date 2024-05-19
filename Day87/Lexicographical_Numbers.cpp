//  https://leetcode.com/problems/lexicographical-numbers/description/

struct Node{
    Node* links[10];
    Node(){
    for(int i=0;i<10;i++){
        links[i]=NULL;
    }
    }
    bool containsKey(char ch){
        return (links[ch-'0']!=NULL);
    }
    void put(char ch,Node* Node){
        links[ch-'0']=Node;
    }
    Node* get(char ch){
        return (links[ch-'0']);
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string num){
        Node* node=root;
        for(int i=0;i<num.size();i++){
        if(!node->containsKey(num[i])){
            node->put(num[i],new Node());
        }
        node=node->get(num[i]);
        }
    }
    void generateNumber(Node* node, int curr, int n, vector<int> &result){
        if(curr > n){
            return;
        }
        if(curr!=0){
            result.push_back(curr);
        }
        for(int i=0;i<10;i++){
            if(node->links[i]){
                generateNumber(node->links[i],curr*10+i,n,result);
            }
        }
    }
    vector<int> generateNumber(int n){
       
       Node* node=root;
      vector<int> result;
            generateNumber(node,0,n,result);
        
        return result;
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie* trie=new Trie();
          vector<int> result;
        for(int i=1;i<=n;i++){
            trie->insert(to_string(i));
        }
        result= trie->generateNumber(n);
        return result;
    }
};