#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      vector<int> cnt = {0,0};
      for (auto s : students) {
        cnt[s] += 1;
      }
      for (auto s : sandwiches) {
        if (cnt[s] >= 0) {
          cnt[s] -= 1;
        } else {
          break;
        }
      }
      return cnt[0] + cnt[1];
    }
};