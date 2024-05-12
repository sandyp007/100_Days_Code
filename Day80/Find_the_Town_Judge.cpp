//  https://leetcode.com/problems/find-the-town-judge/description/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Initialize two maps: one to keep track of the number of people trusting someone,
        // and another to keep track of the number of people trusted by someone.
        unordered_map<int, int> trustCounts;
        unordered_map<int, int> trustedCounts;

        // Iterate through the trust array to update the counts.
        for (const auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            trustCounts[a]++;
            trustedCounts[b]++;
        }

        // Iterate through the people and find the person who is trusted by everyone (n - 1 times)
        // and who trusts nobody.
        for (int i = 1; i <= n; ++i) {
            if (trustCounts[i] == 0 && trustedCounts[i] == n - 1) {
                return i;
            }
        }

        // If no such person is found, return -1.
        return -1;
    }
};
