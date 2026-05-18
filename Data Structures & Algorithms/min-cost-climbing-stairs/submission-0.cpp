class Solution {
public: 

    vector<int> dp;

    int helper(vector<int>& cost, int index){
        if(index >= cost.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int one_step = cost[index] + helper(cost, index + 1);
        int two_step = cost[index] + helper(cost, index + 2);

        return dp[index] = min(one_step, two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();

        dp.resize(n + 1, -1);
        helper(cost, 0);

        return min(dp[0], dp[1]);
    }
};
