int delRow[] = {-1, 1, 0, 0};
int delCol[] = {0, 0, -1, 1};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = '#';
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int currRow = curr.first;
            int currCol = curr.second;

            for (int i = 0; i < 4; i++) {
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                if (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size() && board[newRow][newCol] == 'O') {
                    board[newRow][newCol] = '#';
                    q.push({newRow, newCol});
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '#') {board[i][j] = 'O';}
                else if (board[i][j] == 'O') {board[i][j] = 'X';}
            }
        }
    }
};
