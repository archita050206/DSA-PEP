#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &board, int row, int col)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || visited[i][j] || board[i][j] == 'X')
            return;
        visited[i][j] = true;
        dfs(i - 1, j, visited, board, row, col);
        dfs(i + 1, j, visited, board, row, col);
        dfs(i, j - 1, visited, board, row, col);
        dfs(i, j + 1, visited, board, row, col);
    }
    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &visited, vector<vector<char>> &board, int row, int col)
    {
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if ((i - 1) >= 0 && board[i - 1][j] == 'O' && !visited[i - 1][j])
                {
                    q.push({i - 1, j});
                    visited[i - 1][j] = true;
                }
                if ((i + 1) < row && board[i + 1][j] == 'O' && !visited[i + 1][j])
                {
                    q.push({i + 1, j});
                    visited[i + 1][j] = true;
                }
                if ((j - 1) >= 0 && board[i][j - 1] == 'O' && !visited[i][j - 1])
                {
                    q.push({i, j - 1});
                    visited[i][j - 1] = true;
                }
                if ((j + 1) < col && board[i][j + 1] == 'O' && !visited[i][j + 1])
                {
                    q.push({i, j + 1});
                    visited[i][j + 1] = true;
                }
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        // rows
        for (int j = 0; j < col; j++)
        {
            if (!visited[0][j] && board[0][j] == 'O')
            {
                // dfs(0,j,visited,board,row,col);
                q.push({0, j});
                visited[0][j] = true;
            }
            if (!visited[row - 1][j] && board[row - 1][j] == 'O')
            {
                // dfs(row-1,j,visited,board,row,col);
                q.push({row - 1, j});
                visited[row - 1][j] = true;
            }
        }
        // cols
        for (int i = 0; i < row; i++)
        {
            if (!visited[i][0] && board[i][0] == 'O')
            {
                // dfs(i,0,visited,board,row,col);
                q.push({i, 0});
                visited[i][0] = true;
            }
            if (!visited[i][col - 1] && board[i][col - 1] == 'O')
            {
                // dfs(i,col-1,visited,board,row,col);
                q.push({i, col - 1});
                visited[i][col - 1] = true;
            }
        }
        bfs(q, visited, board, row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};