#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void rotNeighbours(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& freshCount) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> rowDir = {-1, 0, 1, 0};
        vector<int> colDir = {0, 1, 0, -1};
        
        int qsize = q.size(); // Snapshots current level size
        for (int i = 0; i < qsize; i++) {
            auto [row, col] = q.front();
            q.pop();
            
            for (int j = 0; j < 4; j++) {
                int curRow = row + rowDir[j];
                int curCol = col + colDir[j];
                
                if (curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols && grid[curRow][curCol] == 1) {
                    grid[curRow][curCol] = 2;
                    freshCount--;
                    q.push({curRow, curCol});
                }
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }
        
        if (freshCount == 0) return 0;
        
        int time = 0;
        
        // Loop runs as long as there are rotten oranges to process AND fresh ones left
        while (!q.empty() && freshCount > 0) {
            rotNeighbours(grid, q, freshCount);
            time++;
        }
        
        return freshCount == 0 ? time : -1;
    }
};