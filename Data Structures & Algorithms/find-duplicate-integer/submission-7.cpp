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
                //we need abs here to check values of index which are already marked as negative, but those values are not yet visited
                // 2 1 1
                // 1st Iteration - i = 0, index = 2 - 1 == 1, 2 -1 1
                // 2nd Iteration - i = 1, index = abs(-1) - 1 == 0, -2 -1 1
                // 3rd Iteration - i = 2, index = 1 - 1 == 0, already negative so return 1
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }

        return -1;
        
    }
};
