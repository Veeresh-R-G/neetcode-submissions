class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> umap;

        for(int i = 0; i < n; i++){
            int curr = nums[i];
           if(umap.find(curr) != umap.end() and (i - umap[curr]) <= k){
                return true;
           } 
            umap[curr] = i;
           

        }

        return false;
    }
};