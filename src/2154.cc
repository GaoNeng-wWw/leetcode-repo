#include <bits/stdc++.h>
#include <set>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
      set<int> st(nums.begin(), nums.end());
      int o = original;
      while (
        st.find(o) != st.end()
      ) {
        o *= 2;
      }
      return o;
    }
}; 