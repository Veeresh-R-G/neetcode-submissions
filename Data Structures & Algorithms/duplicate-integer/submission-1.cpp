class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;

        for(auto &ele: nums){
            if(umap.find(ele) != umap.end()){
                return true;
            } else{
                umap[ele] = 1;
            }
        }

        return false;
    }
};