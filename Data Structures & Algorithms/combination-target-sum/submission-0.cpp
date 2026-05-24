class Solution {
public:

    vector<vector<int>> ans;

    void helper(vector<int>& nums, vector<int> &temp, int target, int ind){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0 || ind >= nums.size()){
            return;
        }

        temp.push_back(nums[ind]);
        helper(nums, temp, target - nums[ind], ind);
        temp.pop_back();
        helper(nums, temp, target, ind + 1);

        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int> temp;
        helper(nums, temp, target, 0);
        return ans;

    }  
};
