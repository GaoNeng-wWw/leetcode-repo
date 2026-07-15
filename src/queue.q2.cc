#include <deque>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
      deque<pair<int, int>> dq = {};
      for (int i=0;i<tickets.size();i++) {
        dq.push_back(pair(i, tickets[i]));
      }
      int s = 0;
      while (!dq.empty()) {
        s += 1;
        pair<int,int> p = dq.front();
        dq.pop_front();
        int idx = p.first;
        int t = p.second;
        t -= 1;
        if (t == 0 && idx == k) {
          return s;
        }
        if (t == 0 && idx != k) {
          continue;
        }
        dq.push_back(pair(idx, t));
      }
      return s;
    }
};