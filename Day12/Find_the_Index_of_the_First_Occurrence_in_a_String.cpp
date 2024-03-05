// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ 

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                bool flag=true;
                for(int k=0;k<m;k++){
                    if(needle[k]!=haystack[i+k]){
                        flag=false;
                        break;
                    }
                }
                if(flag)
                return i;
            }
        }
        return -1;
    }
};