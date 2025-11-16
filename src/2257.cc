/**

给你两个整数 m 和 n 表示一个下标从 0 开始的 m x n 网格图。同时给你两个二维整数数组 guards 和 walls ，其中 guards[i] = [rowi, coli] 且 walls[j] = [rowj, colj] ，分别表示第 i 个警卫和第 j 座墙所在的位置。

一个警卫能看到 4 个坐标轴方向（即东、南、西、北）的 所有 格子，除非他们被一座墙或者另外一个警卫 挡住 了视线。如果一个格子能被 至少 一个警卫看到，那么我们说这个格子被 保卫 了。

请你返回空格子中，有多少个格子是 没被保卫 的。

 
*/

static constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
      vector<vector<int>> grid = vector<vector<int>>(m, vector<int>(n,0));
      int ans = 0;

      for (auto guard : guards) {
        int x = guard[0];
        int y = guard[1];
        grid[x][y] = -1;
      }
      for (auto wall : walls) {
        int x = wall[0];
        int y = wall[1];
        grid[x][y] = -1;
      }
      for (auto guard : guards) {
        for (auto& [dx,dy] : DIRS) {
          int x = guard[0] + dx;
          int y = guard[1] + dy;
          while (
            0 <= x && x < m &&
            0 <= y && y < n &&
            grid[x][y] != -1
          ) {
            grid[x][y] = 1;
            x += dx;
            y += dy;
          }
        }
      }

      for (auto row : grid){
        for (auto col : row) {
          ans += col == 0 ? 1 : 0;
        }
      }
      return ans;
    }
};