class Solution {
private:
    int dfsHelper(vector<vector<int>>& grid , vector<vector<bool>>& visited, int r , int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0 ) return 1;
        if(visited[r][c]) return 0;
        visited[r][c] = true;

        int perimeter = 0;
        vector<int> rowDir = {-1 , 0 , 1 , 0};
        vector<int> colDir = {0 , 1 , 0 , -1};
        for(int i = 0 ; i < 4 ; i++){
            int newRow = r + rowDir[i];
            int newCol = c + colDir[i];
            perimeter += dfsHelper(grid , visited  , newRow , newCol);
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        vector<vector<bool>> visited (rows , vector<bool>(cols,false));
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < cols ; c++){
                if(grid[r][c] == 1){
                    return dfsHelper(grid , visited , r , c);
                }
            }
        }

        return 0;
        
    }
};