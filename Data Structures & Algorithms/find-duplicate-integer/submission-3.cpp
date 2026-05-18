class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        /*
            Sort - T : nlog(n)
            Hashmap - S : n

        */

        for(int i = 0; i < nums.size(); i++){
            int indx = abs(nums[i]) - 1;
            if(nums[indx] < 0){
                return abs(nums[i]);
            } else{
                nums[indx] *= -1;
            }
        }

        return -1;
        
    }
};
