// https://leetcode.com/problems/reverse-string/ 

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Two pointers, i pointing to the start and j pointing to the end of the vector
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            // Swap the characters at positions i and j
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            // Move i one step forward and j one step backward
            i++;
            j--;
        }
    }
};