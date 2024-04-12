//  https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>map;
        for(auto x:s)
        map[x]++;           //finding occurences of all the characters

        for(auto x:t){
            if(map.find(x)==map.end())
            return x;           //if not found then return the character and that is the answer
            if(map[x]>1)
            map[x]--;       //decreasing the frequency of the character
            else
            map.erase(x);     //erasing the key if the occurence of the character is 1
            
        }


        return '1';  //never reached 
        
    }
};