int delRow[] = {-1, 1, 0, 0};
int delCol[] = {0, 0, -1, 1};

class Solution {
public:
    void utilityDfs(int sr, int sc, int& count, vector<vector<int>>& grid) {
        grid[sr][sc] = 0;
        count++;

        for (int i = 0; i < 4; i++) {
            int newRow = sr + delRow[i];
            int newCol = sc + delCol[i];

            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                utilityDfs(newRow, newCol, count, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    utilityDfs(i, j, count, grid);
                    maxArea = max(maxArea, count);
                }
            }
        }

        return maxArea;
    }
};
