class Solution {
private:
    void dfs (std::vector<vector<char>>& grid , int r , int c){
        int rows = grid.size();
        int cols = grid[0].size();
        if ( r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0' ){
            return ;
        }
        grid[r][c] = '0';
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
public:
    int numIslands(std::vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < cols ; c++){
                if (grid[r][c] == '1'){
                    dfs(grid,r,c);
                    count++;
                }
            }
        }
        return count;
    }
};
