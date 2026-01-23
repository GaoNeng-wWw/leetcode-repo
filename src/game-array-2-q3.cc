#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> ans = {};
      for (auto n : nums) {
        int i = abs(n) - 1;
        if (nums[i] > 0) {
          nums[i] = -nums[i];
        }
      }
      for (int i=0;i<nums.size();i++) {
        if (nums[i] > 0) {
          ans.push_back(i+1);
        }
      }
      return ans;
    }
};