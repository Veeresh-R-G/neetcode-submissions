class Solution {
public:
    
    vector<vector<int>> ans;

    void helper(vector<int>& nums, vector<int>& temp, int ind, int k){
        if(ind >= nums.size() && temp.size() != k){
            return;
        }

        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        helper(nums, temp, ind + 1, k);
        temp.pop_back();
        helper(nums, temp, ind + 1, k);
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<int> nums, temp;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        
        helper(nums, temp, 0, k);
        return ans;
    }
};