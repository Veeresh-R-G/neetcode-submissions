class Solution {
public:

    vector<int> dp;
    int helper(int ind, vector<int>& nums){
        if(ind >= nums.size()){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }
        //1 + 3
        //3
        int steal = nums[ind] + helper(ind + 2, nums);
        int leave = helper(ind + 1, nums);
        return dp[ind] = max(steal, leave);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        dp.resize(n + 1, -1);
        return helper(0, nums);
    }
};
