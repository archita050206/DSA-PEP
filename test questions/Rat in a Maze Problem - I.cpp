#include<vector>
#include<string>
using namespace std;
class Solution
{
public:
    void dfs(int i, int j, string &temp, vector<vector<bool>> &visited, int n, vector<string> &ans, vector<vector<int>> &maze)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] || maze[i][j] == 0)
            return;
        if (i == (n - 1) && j == (n - 1))
        {
            ans.push_back(temp);
            return;
        }

        visited[i][j] = true;
        temp.push_back('D');
        dfs(i + 1, j, temp, visited, n, ans, maze);
        temp.pop_back();
        temp.push_back('L');
        dfs(i, j - 1, temp, visited, n, ans, maze);
        temp.pop_back();
        temp.push_back('R');
        dfs(i, j + 1, temp, visited, n, ans, maze);
        temp.pop_back();
        temp.push_back('U');
        dfs(i - 1, j, temp, visited, n, ans, maze);
        temp.pop_back();

        visited[i][j] = false;
    }
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here
        int n = maze.size();
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return {};
        vector<string> ans;
        string temp = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        dfs(0, 0, temp, visited, n, ans, maze);
        return ans;
    }
};