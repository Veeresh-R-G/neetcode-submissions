class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &nums, vector<int>& temp, int ind){
        if(ind >= nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        helper(nums, temp, ind + 1);
        temp.pop_back();
        helper(nums, temp, ind + 1);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        helper(nums, temp, 0);    
        return ans;
    }
};
