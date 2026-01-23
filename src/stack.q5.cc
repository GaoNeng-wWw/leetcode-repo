#include <vector>
#include <stack>

/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
如果气温在这之后都不会升高，请在该位置用 0 来代替。
*/

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<int> st{};
      int n = temperatures.size();
      vector<int> ans = vector<int>(n, 0);
      for (int i=0;i < n;i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
          int j = st.top(); st.pop();
          ans[j] = i - j;
        }
        st.push(i);
      }
      return ans;
    }
};