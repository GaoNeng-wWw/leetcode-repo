#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();
      constexpr int dirs[4][2] = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
      };
      vector<vector<int>> vis(n,vector<int>(n, 0));
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq{};
      vector<int> cell = {
        grid[0][0],
        0,0
      };
      pq.push(cell);
      while (pq.size()) {
        vector<int> item = pq.top();
        int node = item[0];
        int x = item[1];
        int y = item[2];
        pq.pop();
        if (vis[x][y]) {
          continue;
        }
        vis[x][y] = 1;
        if (x == n-1 && y == n-1) {
          return node;
        }
        for (
          auto dir : dirs
        ) {
          int nx = x+dir[0];
          int ny = y+dir[1];
          if (
            nx >= 0 && nx < n &&
            ny >= 0 && ny < n &&
            !vis[nx][ny]
          ) {
            int mx = max(node, grid[nx][ny]);
            vector<int> cell = vector<int>{mx, nx, ny};
            pq.push(cell);
          }
        }
      }
      return -1;
    }
};