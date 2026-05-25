class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> helper(vector<int>&nums){
        if(nums.size() == 0){
            return {{}};
        }

        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = helper(temp);
        vector<vector<int>> ans;
        for(auto &p: perms){
            for(int i = 0; i <= p.size();i++){
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                ans.push_back(p_copy);
            }
        }
        return ans;
    }   

    void helper_2(vector<int>&nums, vector<int>& perm, int mask){
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!(mask & (1 << i))){
                perm.push_back(nums[i]);
                helper_2(nums, perm, mask | (1 << i));
                perm.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> perm;
        helper_2(nums, perm, 0);
        return res;
    }
};
