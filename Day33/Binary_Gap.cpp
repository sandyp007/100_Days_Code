//  https://leetcode.com/problems/binary-gap/

class Solution {
public:
	int binaryGap(int n) {
		int lastone = 32;
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			if (n & (1 << i)) {
				ans = max(ans, i - lastone);
				lastone = i;
			}
		}
		return ans;
	}
};