//  https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number(int num)
    {
        string s = to_string(num); //convert (num) into string, to iterate over each element
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        }
        return stoi(s); // return the converted(into int) s
    }
};