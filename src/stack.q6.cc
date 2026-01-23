#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      vector<int> dmy{};
      dmy.push_back(0);
      for (auto x : heights) dmy.push_back(x);
      dmy.push_back(0);

      stack<int> st{};
      int ans = 0;
      for (int i=0;i<dmy.size();i++) {
        while (!st.empty() && dmy[i] < dmy[st.top()]) {
          int mid = st.top(); st.pop();
          int h = dmy[mid];
          int w = i - st.top() - 1;
          ans = max(ans, h * w);
        }
        st.push(i);
      }
      return ans;
    }
};