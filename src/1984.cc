#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int ans = 10e5;
      for (int i = k-1; i < n;i++) {
        ans = min(
          nums[i] - nums[i-k+1],
          ans
        );
      }
      return ans;
    }
};