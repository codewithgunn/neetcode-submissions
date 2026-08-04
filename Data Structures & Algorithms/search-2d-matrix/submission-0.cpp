class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows*cols;
        int left = 0;
        int right = n - 1;
        while(left <= right){
            int mid = left + (right-left)/2;
            int midRow = mid/cols;
            int midCol = mid%cols;
            if(matrix[midRow][midCol] == target){
                return true;
            }
            else if(matrix[midRow][midCol] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
};
