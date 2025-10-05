#include <bits/stdc++.h>
#include <vector>

using namespace std;

static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
  vector<vector<int>> heights;
  void dfs(
    int row,
    int col,
    vector<vector<bool>>& ocean
  ){
    int m = ocean.size();
    int n = ocean[0].size();
    if (ocean[row][col]) {
      return;
    }
    ocean[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
            dfs(newRow, newCol, ocean);
        }
    }
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    this->heights = heights;
    int n = heights[0].size();
    int m = heights.size();
    vector<vector<bool>> o1(m, vector<bool>(n, false));
    vector<vector<bool>> o2(m, vector<bool>(n, false));
    for (int i=0;i<m;i++){
      dfs(i,0, o1);
    }
    for (int j=1;j<n;j++) {
      dfs(0,j, o1);
    }
    for (int i = 0; i < m; i++) {
      dfs(i, n - 1, o2);
    }
    for (int j = 0; j < n - 1; j++) {
      dfs(m - 1, j, o2);
    }
    vector<vector<int>> result;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (o1[i][j] && o2[i][j]) {
            vector<int> cell;
            cell.emplace_back(i);
            cell.emplace_back(j);
            result.emplace_back(cell);
        }
      }
    }
    return result;
  }
};