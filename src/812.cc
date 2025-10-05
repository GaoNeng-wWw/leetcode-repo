#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
      double ans = 0;
      for (int i=0;i<points.size();i++){
        for (int j=i+1;j<points.size()-1;j++){
          for (int k=j+1;k<points.size()-1;k++){
            double a = sqrt((points[i][1] - points[j][1]) * (points[i][1] - points[j][1]) + (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]));
            double b = sqrt((points[i][1] - points[k][1]) * (points[i][1] - points[k][1]) + (points[i][0] - points[k][0]) * (points[i][0] - points[k][0]));
            double c = sqrt((points[j][1] - points[k][1]) * (points[j][1] - points[k][1]) + (points[j][0] - points[k][0]) * (points[j][0] - points[k][0]));
            double p = (a + b + c) / 2;
            ans = max(ans, sqrt(p * (p - a) * (p - b) * (p - c)));
          }
        }
      }
      return ans;
    }
};