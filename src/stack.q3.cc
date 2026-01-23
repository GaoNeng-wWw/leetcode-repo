#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<int> res(n, 0);
    stack<int> st; // 存储函数 ID
    int prev_time = 0;

    for (const string &log : logs) {
      // 解析字符串 "id:type:timestamp"
      int first_colon = log.find(':');
      int last_colon = log.rfind(':');
      int id = stoi(log.substr(0, first_colon));
      string type = log.substr(first_colon + 1, last_colon - first_colon - 1);
      int timestamp = stoi(log.substr(last_colon + 1));

      if (type == "start") {
        if (!st.empty()) {
          res[st.top()] += timestamp - prev_time;
        }
        st.push(id);
        prev_time = timestamp; // 更新下一次计算的起点
      } else {
        res[st.top()] += timestamp - prev_time + 1;
        st.pop();
        prev_time = timestamp + 1;
      }
    }
    return res;
  }
};