int delRow[] = {-1, 1, 0, 0};
int delCol[] = {0, 0, -1, 1};

class Solution {
public:
    void utilityDfs(int sr, int sc, vector<vector<char>>& grid) {
        grid[sr][sc] = '0';

        for (int i = 0; i < 4; i++) {
            int newRow = sr + delRow[i];
            int newCol = sc + delCol[i];

            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == '1') {
                utilityDfs(newRow, newCol, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    utilityDfs(i, j, grid);
                }
            }
        }

        return count;
    }
};
