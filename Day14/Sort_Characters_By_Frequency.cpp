// https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:
    string frequencySort(string s){
        unordered_map<char, int> freqMap;

    //  Count character frequencies
    for (char c : s) {
        freqMap[c]++;
    }

    //  Sort characters based on frequency
    sort(s.begin(), s.end(), [&](char a, char b) {
        if (freqMap[a] == freqMap[b]) {
            return a < b; // If frequencies are equal, sort by character order
        }
        return freqMap[a] > freqMap[b];
    });

    // Build the sorted string
    string sortedString;
    for (char c : s) {
        sortedString += c;
    }

    return sortedString;
    }
};