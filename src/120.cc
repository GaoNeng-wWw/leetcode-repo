#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f = vector<vector<int>>(n, vector<int>(n, 0));
        f[0][0] = triangle[0][0];
        for (int x = 1; x < n; x ++) {
          f[x][0] = f[x-1][0] + triangle[x][0];
          for (int y = 1; y < x; y++){
            f[x][y] = min(f[x-1][y], f[x-1][y-1]) + triangle[x][y];
          }
          f[x][x] = f[x-1][x-1] + triangle[x][x];
        }
        int ans = 0x3f3f3f;
        for (auto n : f[f.size()-1]) {
          ans = min(ans,n);
        }
        return ans;
    }
};

int main(){
  Solution s{};
  vector<vector<int>> q = {{2},{3,4},{6,5,7},{4,1,8,3}};
  std::cout << s.minimumTotal(q) << std::endl;
}