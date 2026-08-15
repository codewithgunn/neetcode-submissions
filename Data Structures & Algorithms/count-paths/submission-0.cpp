class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(n , vector<int>(m,0)); 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || j == 0){
                    grid[i][j] = 1;
                }
                else{
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[n-1][m-1];
    }
};
