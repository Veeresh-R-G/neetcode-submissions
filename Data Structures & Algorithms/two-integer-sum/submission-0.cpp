class Solution {
public:

    int min(int a, int b){
        return a >= b ? b : a;
    }

    int max(int a, int b){
        return a >= b ? a : b;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i = 0;
        unordered_map<int, int> umap;

        for(auto &ele: nums){
            int diff = target - ele;
            if(umap.find(diff) != umap.end()){
                return {min(i, umap[diff]), max(i, umap[diff])};
            } else{
                umap[ele] = i;
            }
            i++;
        }

        return {};
    }
};
