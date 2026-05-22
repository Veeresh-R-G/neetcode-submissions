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
  
        int steal = nums[ind] + helper(ind + 2, nums);
        int leave = helper(ind + 1, nums);
        return dp[ind] = max(steal, leave);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> t1;
        vector<int> t2;

        for(int i = 0; i < n - 1; i++){
            t1.push_back(nums[i]);
        }

        for(int i = 1; i < n; i++){
            t2.push_back(nums[i]);
        }

        dp.assign(t1.size(), -1);
        int temp1 = helper(0, t1);
        dp.assign(t2.size(), -1);
        int temp2 = helper(0, t2);
        return max(temp1, temp2);


    }
};
