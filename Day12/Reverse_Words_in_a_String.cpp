// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        
        stringstream obj(s); // breaking input string into word using string stream 
                            
        string ans = "";
        string str;
        
        vector<string> v;
        while(obj>>str)     // read individual word in string str 
        {
           v.push_back(str);    
        }
        
        reverse(v.begin(),v.end());
        
        for(auto j : v)
        {
            if(ans.size())  ans+=' ';
            ans+=j;
        }
        
        return ans;
    }
};