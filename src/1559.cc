#include <cstdint>
#include <vector>

using namespace std;

constexpr int DIRS[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
;

class Solution {
public:
  bool containsCycle(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector vis(m, vector<int8_t>(n));
    auto dfs = [&](this auto &&dfs, int x, int y, int px, int py) -> bool {
      vis[x][y] = 1;
      for (auto [dx, dy] : DIRS) {
        int i = x + dx, j = y + dy;
        if ((i != px || j != py) && 0 <= i && i < m && 0 <= j && j < n &&
            grid[i][j] == grid[x][y] && (vis[i][j] || dfs(i, j, x, y))) {
          return true;
        }
      }
      return false;
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!vis[i][j] && dfs(i, j, -1, -1)) {
          return true;
        }
      }
    }
    return false;
  }
};