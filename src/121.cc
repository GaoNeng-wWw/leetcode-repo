#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int p = 0xffff;
      int c = -1;
      for (auto price : prices) {
        p = min(p, price);
        c = max(c, p-c);
      }
      return c;
    }
};

int main(){
  Solution s{};
  vector<int> q = vector<int>({1,2,3,4,5});
  s.maxProfit(q);
  return 0;
}