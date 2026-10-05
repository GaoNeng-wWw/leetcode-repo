#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
      vector<int> st = {0};
      for (auto ch : s) {
        if (ch == '(') {
          st.push_back(0);
        } else {
          int cur = st[st.size() - 1];
          st.pop_back();
          st[st.size() - 1] += max(cur * 2, 1);
        }
      }
      return st[st.size() - 1];
    }
};
