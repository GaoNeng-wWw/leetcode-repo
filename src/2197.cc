#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    inline int gcd(const int a, const int b){
      return __gcd(a,b);
    }
    inline int lcm(const int a, const int b){
      return a/this->gcd(a, b)*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
      vector<int> st = {};
      for (auto x : nums) {
        while (!st.empty() && this->gcd(x, st.back()) > 1) {
          x = this->lcm(x, st.back());
          st.pop_back();
        }
        st.push_back(x);
      }
      return st;
    }
};

int main(){
  Solution s;
  vector<int> nums = {6,4,3,2,7,6,2};
  s.replaceNonCoprimes(nums);
}