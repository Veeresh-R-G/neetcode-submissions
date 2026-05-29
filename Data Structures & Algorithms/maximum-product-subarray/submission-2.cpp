class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int maxP = INT_MIN;

        int pre = 1;
        int post = 1;

        for(int i = 0; i < n; i++){
            if(pre == 0){
                pre = 1;
            } 

            if(post == 0){
                post = 1;
            }

            pre *= nums[i];
            post *= nums[n - i - 1];

            maxP = max(maxP, max(pre, post));

        }

        return maxP;
    }
};
