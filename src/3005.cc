#include <vector>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      int size = nums.size();
      int count = 0;
      int maxFrequency = 1;
      int max[101];
      for (int idx = 0; idx < size; idx++) {
          max[nums[idx]]++;
          // 当当前数字的出现频率大于最大出现频率时 更新count与maxFrequency
          if (max[nums[idx]] > maxFrequency) {
              maxFrequency = max[nums[idx]];
              count = maxFrequency;
          } else if (max[nums[idx]] == maxFrequency) // 仅当当前数字出现频率等于最大出现频率时使得count+=当前数字的出现频率
              count += max[nums[idx]];
      }
      return count;
    }
};