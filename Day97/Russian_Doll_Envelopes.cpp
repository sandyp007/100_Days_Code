//  https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
	private:

		int solve(int n,vector<int> &nums){

			vector<int> ans;
			ans.push_back(nums[0]);

			for(int i = 1; i < n; i++){
				if(nums[i] > ans.back()){
					ans.push_back(nums[i]);
				}else{
					int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
					ans[index] = nums[i];
				}
			}

			return ans.size();

		}
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {

		int n = envelopes.size();

		if(n == 0) return 0;

		sort(envelopes.begin(),envelopes.end(),[](vector<int> &a, vector<int> &b){
			if(a[0] == b[0]){   
				return a[1] > b[1];
			}
			return a[0] < b[0];
		});


		vector<int> nums;

		for(int i = 0; i < n; i++){
			nums.push_back(envelopes[i][1]);
		}

		return solve(n,nums);
	}
};