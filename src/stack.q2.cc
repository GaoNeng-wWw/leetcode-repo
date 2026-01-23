#include <iterator>
#include <vector>
#include <string>

using namespace std;

int parseNum(string val){
  return stoi(val);
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      vector<int> st = {};
      for (int i=0;i<tokens.size();i++) {
        string tk = tokens[i];
        if (tk == "+" || tk == "-" || tk == "*" || tk == "/") {
          int rhs = st.back();st.pop_back();
          int lhs = st.back();st.pop_back();
          if (tk == "+") {
            st.push_back(lhs + rhs);
          }
          if (tk == "-") {
            st.push_back(lhs - rhs);
          }
          if (tk == "*") {
            st.push_back(lhs * rhs);
          }
          if (tk == "/") {
            st.push_back(lhs/rhs);
          }
          continue;
        }
        st.push_back(parseNum(tk));
      }
      return st[0];
    }
};