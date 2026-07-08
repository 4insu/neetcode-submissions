int delRow[] = {-1, 1, 0, 0};
int delCol[] = {0, 0, -1, 1};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {q.push({0, {i, j}});}
            }
        }

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int currDst = curr.first;
            int currRow = curr.second.first;
            int currCol = curr.second.second;

            for (int i = 0; i < 4; i++) {
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == INT_MAX) {
                    grid[newRow][newCol] = currDst + 1;
                    q.push({currDst + 1, {newRow, newCol}});
                }
            }
        }
    }
};
