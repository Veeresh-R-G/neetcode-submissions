class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int right = n - 1;
        int top = 0;


        while(top < m && right >= 0){
            if(matrix[top][right] == target){
                return true;
            }
            else if(matrix[top][right] > target){
                right--;
            } else{
                top++;
            }
        }

        return false;
    }
};
