class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& nums, vector<int>& temp, int ind, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0 or ind >= nums.size()){
            return;
        }

        temp.push_back(nums[ind]);
        helper(nums, temp, ind + 1, target - nums[ind]);
        temp.pop_back();

        while(ind + 1 < nums.size() and nums[ind] == nums[ind + 1]){
            ind++;
        }
        helper(nums, temp, ind + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, temp, 0, target);
        return ans;
    }
};
