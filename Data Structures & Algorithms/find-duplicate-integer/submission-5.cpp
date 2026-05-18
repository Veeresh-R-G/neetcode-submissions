class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        /*
            Sort - T : nlog(n)
            Hashmap - S : n

        */

        for(int i = 0; i < nums.size(); i++){
       
            if(nums[abs(nums[i]) - 1] < 0){
                return abs(nums[i]);
            } else{
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }

        return -1;
        
    }
};
