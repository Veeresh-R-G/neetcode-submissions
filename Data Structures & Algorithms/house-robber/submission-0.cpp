class Solution {
public:

    vector<int> dp;

    int helper(vector<int>& nums, int index){
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int steal = nums[index] + helper(nums, index + 2);
        int pass = helper(nums, index + 1);

        return dp[index] = max(steal, pass);
    }

    int rob(vector<int>& nums) {
    
        int n = nums.size();
        dp.resize(n, -1);

        return helper(nums, 0);
    }
};
