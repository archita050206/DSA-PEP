#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &image, int color, int ogcolor, int row, int col)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || image[i][j] == color || image[i][j] != ogcolor)
            return;
        image[i][j] = color;
        dfs(i - 1, j, image, color, ogcolor, row, col); // up
        dfs(i + 1, j, image, color, ogcolor, row, col); // down
        dfs(i, j - 1, image, color, ogcolor, row, col); // left
        dfs(i, j + 1, image, color, ogcolor, row, col);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> q;

        q.push({sr, sc});
        int ogcolor = image[sr][sc];
        if (ogcolor == color)
            return image;
        image[sr][sc] = color;
        while (!q.empty())
        {
            int size = q.size();
            for (int k = 0; k < size; k++)
            {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // top
                if ((i - 1) >= 0 && image[i - 1][j] == ogcolor)
                {
                    image[i - 1][j] = color;
                    q.push({i - 1, j});
                }
                // down
                if ((i + 1) < image.size() && image[i + 1][j] == ogcolor)
                {
                    image[i + 1][j] = color;
                    q.push({i + 1, j});
                }
                // left
                if ((j - 1) >= 0 && image[i][j - 1] == ogcolor)
                {
                    image[i][j - 1] = color;
                    q.push({i, j - 1});
                }
                // right
                if ((j + 1) < image[0].size() && image[i][j + 1] == ogcolor)
                {
                    image[i][j + 1] = color;
                    q.push({i, j + 1});
                }
            }
        }
        dfs(sr, sc, image, color, ogcolor, image.size(), image[0].size());
        return image;
    }
};