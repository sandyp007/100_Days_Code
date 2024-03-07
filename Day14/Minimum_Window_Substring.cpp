// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int tn= t.size();
        int left = 0, right;
        unordered_map<char, int> mp, tmp;
        
        // Count the characters in string t
        for (char c : t)
            tmp[c]++;
        
        int count = 0; // Counter for matching characters
        
        int minLength = INT_MAX; // Length of the minimum window
        int minLeft = 0; // Start index of the minimum window
        
        for (right = 0; right < n; right++) {
            char c = s[right];
            
            // Skip characters not present in string t
            if (tmp.count(c) == 0) continue;
            
            // Increment the count of matching characters
            mp[c]++;
            
            // Check if the current character count matches the required count
            if (mp[c] <= tmp[c]) count++;
            
            // If all characters of t are found in the current window
            if (count == tn) {
                // Try to minimize the window by moving the left pointer
                while (tmp.count(s[left])==0|| mp[s[left]]>tmp[s[left]]) {
                    if (mp.count(s[left])!=0) mp[s[left]]--;
                    left++;
                }
                
                // Update the minimum window if necessary
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }
            }
        }
        
        // If no valid window found, return an empty string
        if (minLength == INT_MAX) return "";
        
        // Return the minimum window substring
        return s.substr(minLeft, minLength);
    }
};