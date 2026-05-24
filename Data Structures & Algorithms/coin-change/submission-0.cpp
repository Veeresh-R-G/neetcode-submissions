class Solution {
public:

    vector<int> dp;

    int helper(vector<int>& coins, int amt){
        if(amt == 0){
            return 0;
        }

        if(dp[amt] != -1){
            return dp[amt];
        }
        int res = 1e9;

        for(auto &coin: coins){
            if(amt - coin >= 0){
                res = min(res, 1 + helper(coins, amt - coin));
            }
        }

        return dp[amt] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        dp.resize(amount + 1, -1);
        int res = helper(coins, amount);
        return res == 1e9 ? -1 : res;
    }
};
