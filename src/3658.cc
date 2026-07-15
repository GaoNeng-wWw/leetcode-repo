#include <array>
#include <numeric>

template<int N>
consteval auto make_odd_even() {
  std::array<int, (N+1)/2> odd = {};
  std::array<int, (N+1)/2> even = {};
  int oi = 0, ei = 0;
  for (int i=1;i<=N;i++) {
    if (i % 2 == 0) even[ei++] = i;
    else odd[oi++] = i;
  }
  return std::pair{odd, even};
}

constexpr auto p = make_odd_even<2000>();

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
      int os = 0; int es = 0;
      for (int i=0;i<n;i++) {
        os += p.first[i];
        es += p.second[i];
      }
      return std::gcd(os, es);
    }
};