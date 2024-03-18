//  https://leetcode.com/problems/word-break/

class Solution {
public:
    
    unordered_map<string, bool> memo;
    
    bool wordBreakHelp(string word, unordered_map<string, bool>& dict)
    {
        //if present in dict
        if(dict.find(word) != dict.end())
            return true;
        
        //if present in memo, no need to call 
        if(memo.find(word) != memo.end())
            return memo[word];
        
        
        for(int i=0; i<word.length(); i++)
        {
            string left = word.substr(0, i+1); //always starts from beginning
            string right = word.substr(i+1); //remaining string till the last letter;
            
            if(dict.find(left) != dict.end())
            {
                bool ros = wordBreakHelp(right, dict); //rest of the string is recursed
                
                if(ros == true)
                {
                    memo[word] = true; //entire word exists
                    return true;
                }
            }
        }
        
        //if no prefix is found to be matching, word does not exist
        memo[word] = false;
        return false;
          
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string, bool> dict;
        
        for(string s : wordDict)
            dict[s] = true;
        
        return wordBreakHelp(s, dict);
    }
};