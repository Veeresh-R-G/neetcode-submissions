class Solution {
public:
vector<vector<int>> ans;
    vector<int> temp;

    void helper(vector<int>& nums, int ind){
        if(ind >= nums.size()){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[ind]);
        helper(nums, ind + 1);

        temp.pop_back();
        helper(nums, ind + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index = 0;
        helper(nums, index);
        return ans;
    }
};
