#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
      int last = target.at(target.size() - 1);
      vector<int> st = {};
      for (int t : target) {
        st.push_back(t);
      }
      vector<string> res = {};
      for (int i=1;i<=last;i++) {
        res.push_back("Push");
        if (!binary_search(st.begin(),st.end(),i)) {
          res.push_back("Pop");
        }
      }
      return res;
    }
};