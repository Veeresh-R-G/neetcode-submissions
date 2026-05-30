class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = (n * (n + 1)) / 2;

        int arr_sum = 0;

        for(auto &ele: nums){
            arr_sum += ele;
        }

        return s - arr_sum;
    }
};
